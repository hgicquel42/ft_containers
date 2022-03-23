#pragma once

#include "pair.hpp"

namespace ft
{
	/**
	 * @brief Erase by key
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param root 
	 * @param key 
	 */
	template <class K, class V>
	template <class C>
	bool	node<K,V>::erase(node** root, const K& key)
	{
		node* current = search<C>(*root, key);
		if (!current) return (false);
		
		erase(root, current);
		return (true);
	}

	/**
	 * @brief Erase by slot
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param slot 
	 */
	template <class K, class V>
	bool	node<K,V>::erase(node** root, node* current)
	{
		if (!current) return (false);

		if (current->left && current->right) {
			node* min = minimum(current->right);
			current->key = min->key;
			current->value = min->value;
			return (erase(root, min));
		}

		bool color = current->color;

		if (current->right) {
			node* next = current->right;
			next->parent = current->parent;
			*slot(root, current) = next;
			delete current;
			current = next;
		} else if (current->left) {
			node* next = current->left;
			next->parent = current->parent;
			*slot(root, current) = next;
			delete current;
			current = next;
		} else {
			*slot(root, current) = NULL;
			delete current;
			current = NULL;
		}

		if (!current)
			return (true);
		if (color == NRED)
			return (true);
		erasef(root, current);
		return (true);
	}

	/**
	 * @brief Fix after erase (recursive)
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param parent 
	 * @param slot 
	 * @param color 
	 */
	template <class K, class V>
	void	node<K,V>::erasef(node** root, node* current)
	{
		if (!current) return ;

		node* parent = current->parent;

		if (!parent) {
			current->color = NBLACK;
			return ;
		}

		node* sibling = node::sibling(current);
		if (!sibling) return ;

		if (sibling->color == NRED) {
			sibling->color = NBLACK;
			parent->color = NRED;
			
			if (current == parent->left)
				lrotate(root, parent);
			else if (current == parent->right)
				rrotate(root, parent);
			sibling = node::sibling(current);
			if (!sibling) return ;
		}

		if (isblack(sibling->left) && isblack(sibling->right))
		{
			sibling->color = NRED;

			if (parent->color == NRED)
				parent->color = NBLACK;
			else
				erasef(root, parent);
			return ;
		}

		if (current == parent->left && isblack(sibling->right)) {
			if (!sibling->left) return ;
			sibling->left->color = NBLACK;
			sibling->color = NRED;
			rrotate(root, sibling);
			sibling = parent->right;
			if (!sibling) return ;
		}

		if (current == parent->right && isblack(sibling->left)) {
			if (!sibling->right) return ;
			sibling->right->color = NBLACK;
			sibling->color = NRED;
			lrotate(root, sibling);
			sibling = parent->left;
			if (!sibling) return ;
		}

		sibling->color = parent->color;
		parent->color = NBLACK;
		if (current == parent->left) {
			if (sibling->right)
				sibling->right->color = NBLACK;
			lrotate(root, parent);
		} else {
			if (sibling->left)
				sibling->left->color = NBLACK;
			rrotate(root, parent);
		}
	}
}