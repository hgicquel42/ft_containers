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
	node<K,V>*	node<K,V>::minimum2(node* current)
	{
		if (!current->left)
			return (current);
		return (minimum2(current->left));
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::maximum2(node* current)
	{
		if (!current->right)
			return (current);
		return (maximum2(current->right));
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::next(node* current)
	{
		if (!current)
			return (NULL);
		if (current->right)
			return (minimum2(current->right));
		node* parent = current->parent;
		while (parent && current == parent->right)
		{
			current = parent;
			parent = current->parent;
		}
		return (parent);
	}
	
	template <class K, class V>
	node<K,V>*	node<K,V>::previous(node*const* root, node* current)
	{
		if (!current)
			return (maximum2(*root));
		if (current->left)
			return (maximum2(current->left));
		node* parent = current->parent;
		while (parent && current == parent->left)
		{
			current = parent;
			parent = current->parent;
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