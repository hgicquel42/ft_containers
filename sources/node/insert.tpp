#pragma once

#include "node.hpp"
#include "pair.hpp"

namespace ft
{
	/**
	 * @brief Insert by key-value
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param root 
	 * @param key 
	 * @param value 
	 */
	template <class K, class V>
	template <class C>
	pair<node<K,V>*, bool>	node<K,V>::insert(node** root, const K& key, const V& value)
	{
		node* parent = NULL;

		node** slot = node::template spot<C>(&parent, root, key);
		if (!slot) return (ft::make_pair<node*, bool>(NULL, false));
		if (*slot) return (ft::make_pair<node*, bool>(*slot, false));

		node* current = new node<K,V>(parent, key, value, NRED);
		*slot = current;
		insertf(root, current);
		return (ft::make_pair<node*, bool>(current, true));
	}

	/**
	 * @brief Fix after insert (recursive)
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param slot 
	 */
	template <class K, class V>
	void	node<K,V>::insertf(node** root, node* current)
	{
		if (!current) return ;

		node* parent = current->parent;

		if (!parent) {
			current->color = NBLACK;
			return ;
		}

		if (parent->color == NBLACK) {
			return ;
		}

		node* gparent = parent->parent;

		if (!gparent) {
			parent->color = NBLACK;
			return ;
		}

		node* uncle = node::uncle(current);

		if (uncle && uncle->color == NRED) {
			parent->color = NBLACK;
			gparent->color = NRED;
			uncle->color = NBLACK;
			insertf(root, gparent);
			return ;
		}

		else if (parent == gparent->left) {
			if (current == parent->right) {
				lrotate(root, parent);
				parent = current;
			}
			
			rrotate(root, gparent);
			parent->color = NBLACK;
			gparent->color = NRED;
			return ;
		}

		else {
			if (current == parent->left) {
				rrotate(root, parent);
				parent = current;
			}

			lrotate(root, gparent);
			parent->color = NBLACK;
			gparent->color = NRED;
			return ;
		}
	}
}