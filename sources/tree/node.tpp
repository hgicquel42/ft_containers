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
	static void	_print(const node<K,V>* root, const string& prefix, int position)
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
		cout << root->key;
		cout << ": ";
		cout << root->value;
		cout << RESET << "\n";

		string nprefix;
		if (position == -1)
			nprefix = prefix + "│   ";
		else if (position == 1)
			nprefix = prefix + "    ";
		_print(root->left, nprefix, -1);
		_print(root->right, nprefix, 1);
	}

	template <class K, class V>
	void	node<K,V>::print(void) const
	{
		_print(this, "", 0);
	}

	template <class K, class V>
	void	node<K,V>::recolor(void)
	{
		this->color = !this->color;
	}

	template <class K, class V>
	static node<K,V>*	_search(const node<K,V>* root, const K& key)
	{
		if (!root)
			return (NULL);
		if (key == root->key)
			return (root);
		else if (key > root->key)
			return (search(root->right, key));
		else if (key < root->key)
			return (search(root->left, key));
		return (NULL);
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::search(const K& key) const
	{
		return (_search(this, key));
	}

	template <class K, class V>
	static void	_insert(node<K,V>*& root, ft::node<K,V>*const leaf)
	{
		if (!leaf)
			return ;
		if (!root)
			root = leaf;
		else if (leaf->key < root->key)
			_insert(root->left, leaf);
		else if (leaf->key > root->key)
			_insert(root->right, leaf);
	}

	template <class K, class V>
	void	node<K,V>::insert(node*const leaf)
	{
		if (leaf->key < this->key)
			_insert(this->left, leaf);
		else if (leaf->key > this->key)
			_insert(this->right, leaf);
	}
}