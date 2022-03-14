#pragma once

#include <iostream>

#include "node.hpp"

#include "utils/colors.hpp"

namespace ft
{
	template <class K, class V>
	node<K,V>::node(void):	
		key(),
		value(),
		parent(NULL),
		left(NULL),
		right(NULL),
		color(false)
	{}

	template <class K, class V>
	node<K,V>::~node(void)
	{}

	template <class K, class V>
	node<K,V>::node(const node& from):
		key(from.key),
		value(from.value),
		parent(from.parent),
		left(from.left),
		right(from.right),
		color(from.color)
	{}

	template <class K, class V>
	node<K,V>&	node<K,V>::operator=(const node& from)
	{
		if (this == &from)
			return (*this);
		this->key = from.key;
		this->value = from.value;
		this->parent = from.parent;
		this->left = from.left;
		this->right = from.right;
		this->color = from.color;
		return (*this);
	}

	template <class K, class V>
	node<K,V>::node(const K& key, const V& value, bool color):
		key(key),
		value(value),
		left(NULL),
		right(NULL),
		color(color)
	{}

	template <class K, class V>
	void	node<K,V>::recolor(void)
	{
		this->color = !this->color;
	}

	template <class K, class V>
	void	node<K,V>::print(const node* root, const string& prefix, int position)
	{
		if (!root)
			return ;
		cout << prefix;

		if (position == -1)
			cout << "|---";
		else if (position == 1)
			cout << "└---";
		if (root->color == NRED)
			cout << RED;
		cout << root->key << ": " << root->value;
		cout << RESET << "\n";

		string nprefix = prefix;
		if (position == -1)
			nprefix += "│   ";
		else if (position == 1)
			nprefix += "    ";
		print(root->left, nprefix, -1);
		print(root->right, nprefix, 1);
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::search(const node* root, const K& key)
	{
		if (!root)
			return (NULL);
		if (key == root->key)
			return (root);
		else if (key > root->key)
			return (search(root->right, key));
		else
			return (search(root->left, key));
	}

	/**
	 * @brief Left rotate
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param root 
	 */
	template <class K, class V>
	void	node<K,V>::lrotate(node*& root)
	{
		if (!root || !root->right)
			return ;
		node* x = root->right;
		node* y = x->left;
		x->left = root;
		root->right = y;
		root->parent = x;
		if (y)
			y->parent = root;
		root = x;
	}

	/**
	 * @brief Right rotate
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param root 
	 */
	template <class K, class V>
	void	node<K,V>::rrotate(node*& root)
	{
		if (!root || !root->left)
			return ;
		node* x = root->left;
		node* y = x->right;
		x->right = root;
		root->left = y;
		root->parent = x;
		if (y)
			y->parent = root;
		root = x;
	}

	/**
	 * @brief Find an empty slot to insert
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param root 
	 * @param key 
	 * @return node<K,V>*& The empty slot = NULL
	 */
	template <class K, class V>
	node<K,V>*&	node<K,V>::spot(node*& root, const K& key)
	{
		if (!root)
			return (root);
		if (key < root->key)
			return (spot(root->left, key));
		else
			return (spot(root->right, key));
	}

	template <class K, class V>
	void	node<K,V>::insert(node*& root, const K& key, const V& value)
	{
		node*& slot = spot(root, key);

		slot = new node<K,V>(key, value, NRED);

	}
}