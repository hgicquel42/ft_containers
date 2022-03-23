#pragma once

#include "pair.hpp"

namespace ft
{
	template <class K, class V>
	void	node<K,V>::lrotate(node** root, node* current)
	{
		node** slot = node::slot(root, current);
		node* parent = current->parent;
		node* right = current->right;

		current->right = right->left;
		if (right->left)
			right->left->parent = current;

		right->left = current;
		current->parent = right;

		*slot = right;

		right->parent = parent;
	}

	template <class K, class V>
	void	node<K,V>::rrotate(node** root, node* current)
	{
		node** slot = node::slot(root, current);
		node* parent = current->parent;
		node* left = current->left;

		current->left = left->right;
		if (left->right)
			left->right->parent = current;

		left->right = current;
		current->parent = left;

		*slot = left;

		left->parent = parent;
	}
}