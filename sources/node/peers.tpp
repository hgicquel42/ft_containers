#pragma once

#include "node.hpp"

#include <cstdlib>

namespace ft
{
	template <class K, class V>
	node<K,V>**	node<K,V>::sibling(node* current)
	{
		if (!current->parent)
			return (NULL);
		if (current == current->parent->left)
			return (&(current->parent->right));
		if (current == current->parent->right)
			return (&(current->parent->left));
		return (NULL);
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::uncle(node* current)
	{
		if (!current->parent)
			return (NULL);
		return (node::sibling(current->parent));
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::minimum(node** slot)
	{
		if (!(*slot)->left)
			return (slot);
		return (minimum(&(*slot)->left));
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::maximum(node** slot)
	{
		if (!(*slot)->right)
			return (slot);
		return (maximum(&(*slot)->right));
	}

	template <class K, class V>
	node<K,V>*const*	node<K,V>::const_minimum(node*const* slot)
	{
		if (!(*slot)->left)
			return (slot);
		return (minimum(&(*slot)->left));
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::const_maximum(node*const* slot)
	{
		if (!(*slot)->right)
			return (slot);
		return (maximum(&(*slot)->right));
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::next(node** slot)
	{
		if (!slot)
			return (NULL);
		if (!*slot)
			return (slot);
		if ((*slot)->right)
			return (minimum(&(*slot)->right));
		node** parent = &(*slot)->parent;
		while (*parent && *slot == (*parent)->right)
		{
			slot = parent;
			parent = &(*slot)->parent;
		}
		return (parent);
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::previous(node** slot)
	{
		if (!slot)
			return (NULL);
		if (!*slot)
			return (slot);
		if ((*slot)->left)
			return (maximum(&(*slot)->left));
		node** parent = &(*slot)->parent;
		while (*parent && *slot == (*parent)->left)
		{
			slot = parent;
			parent = &(*slot)->parent;
		}
		return (parent);
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::slot(node** root, node* current)
	{
		if (!current->parent)
			return (root);
		if (current == current->parent->left)
			return (&(current->parent->left));
		if (current == current->parent->right)
			return (&(current->parent->right));
		return (NULL);
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::search(node* root, const K& key)
	{
		if (!root)
			return (NULL);
		if (key == root->key)
			return (root);
		if (key > root->key)
			return (search(root->right, key));
		if (key < root->key)
			return (search(root->left, key));
		return (NULL);
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::spot(node** parent, node** root, const K& key)
	{
		if (!root)
			return (NULL);
		if (!*root)
			return (root);
		*parent = *root;
		if (key == (*root)->key)
			return (root);
		if (key < (*root)->key)
			return (spot(parent, &(*root)->left, key));
		if (key > (*root)->key)
			return (spot(parent, &(*root)->right, key));
		return (NULL);
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::random(node** root)
	{
		if (!root)
			return (NULL);
		if (!*root)
			return (root);
		int r = (rand() % 3) - 1;
		if (r == -1)
			return (random(&(*root)->left));
		if (r == 1)
			return (random(&(*root)->right));
		return (root);
	}
}