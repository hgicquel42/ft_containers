#pragma once

#include "node.hpp"

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
	void	node<K,V>::insert(node** root, const K& key, const V& value)
	{
		node* parent = NULL;

		node** slot = spot(&parent, root, key);
		if (!slot || *slot) return ;

		*slot = new node<K,V>(parent, key, value, NRED);
		insertf(root, slot);
		return ;
	}

	/**
	 * @brief Fix after insert (recursive)
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param slot 
	 */
	template <class K, class V>
	void	node<K,V>::insertf(node** root, node** slot)
	{
		if (!slot || !*slot) return ;

		node* current = *slot;
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

		node* uncle = *node::uncle(current);

		if (uncle && uncle->color == NRED) {
			parent->color = NBLACK;
			gparent->color = NRED;
			uncle->color = NBLACK;
			insertf(root, node::slot(root, gparent));
			return ;
		}

		else if (parent == gparent->left) {
			if (current == parent->right) {
				lrotate(node::slot(root, parent));
				parent = current;
			}
			
			rrotate(node::slot(root, gparent));
			parent->color = NBLACK;
			gparent->color = NRED;
			return ;
		}

		else {
			if (current == parent->left) {
				rrotate(node::slot(root, parent));
				parent = current;
			}

			lrotate(node::slot(root, gparent));
			parent->color = NBLACK;
			gparent->color = NRED;
			return ;
		}
	}
}