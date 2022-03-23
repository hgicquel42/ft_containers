#pragma once

#include "node.hpp"

#include <cstdlib>

namespace ft
{
	template <class K, class V>
	node<K,V>*	node<K,V>::sibling(node* current)
	{
		if (!current->parent)
			return (NULL);
		if (current == current->parent->left)
			return (current->parent->right);
		if (current == current->parent->right)
			return (current->parent->left);
		return (NULL);
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::uncle(node* current)
	{
		if (!current->parent)
			return (NULL);
		return (node::sibling(current->parent));
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::minimum(node* current)
	{
		if (!current->left)
			return (current);
		return (minimum(current->left));
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::maximum(node* current)
	{
		if (!current->right)
			return (current);
		return (maximum(current->right));
	}

	template <class K, class V>
	const node<K,V>*	node<K,V>::maximum(const node* current)
	{
		if (!current->right)
			return (current);
		return (maximum(current->right));
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::next(node* current)
	{
		if (!current)
			return (NULL);
		if (current->right)
			return (minimum(current->right));
		node* parent = current->parent;
		while (parent && current == parent->right)
		{
			current = parent;
			parent = current->parent;
		}
		return (parent);
	}
	
	template <class K, class V>
	const node<K,V>*	node<K,V>::next(const node* current)
	{
		if (!current)
			return (NULL);
		if (current->right)
			return (minimum(current->right));
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
			return (maximum(*root));
		if (current->left)
			return (maximum(current->left));
		node* parent = current->parent;
		while (parent && current == parent->left)
		{
			current = parent;
			parent = current->parent;
		}
		return (parent);
	}

	template <class K, class V>
	const node<K,V>*	node<K,V>::previous(const node*const* root, const node* current)
	{
		if (!current)
			return (maximum(*root));
		if (current->left)
			return (maximum(current->left));
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
	template <class C>
	node<K,V>*	node<K,V>::search(node* current, const K& key)
	{
		if (!current)
			return (NULL);
		if (key == current->key)
			return (current);
		if (C()(key, current->key))
			return (node::template search<C>(current->left, key));
		else
			return (node::template search<C>(current->right, key));	
	}

	template <class K, class V>
	template <class C>
	node<K,V>**	node<K,V>::spot(node** parent, node** root, const K& key)
	{
		if (!root)
			return (NULL);
		if (!*root)
			return (root);
		*parent = *root;
		if (key == (*root)->key)
			return (root);
		if (C()(key, (*root)->key))
			return (node::template spot<C>(parent, &(*root)->left, key));
		else
			return (node::template spot<C>(parent, &(*root)->right, key));
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::random(node* current)
	{
		if (!current)
			return (NULL);
		int r = (rand() % 3) - 1;
		if (r == -1)
			return (random(current->left));
		if (r == 1)  
			return (random(current->right));
		return (current);
	}
}