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
	static void	_print(const node<K,V>* node, const string& prefix, int position)
	{
		if (!node)
			return ;
		cout << prefix;

		if (position == -1)
			cout << "|---";
		if (position == 1)
			cout << "└---";
		if (node->color == NRED)
			cout << RED;
		cout << node->key;
		cout << ": ";
		cout << node->value;
		cout << RESET << "\n";

		string nprefix;
		if (position == -1)
			nprefix = prefix + "│   ";
		if (position == 1)
			nprefix = prefix + "    ";
		_print(node->left, nprefix, -1);
		_print(node->right, nprefix, 1);
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
	static node<K,V>*	_search(const node<K,V>* node, const K& key)
	{
		if (!node)
			return (NULL);
		if (key == node->key)
			return (node);
		if (key > node->key)
			return (search(node->right, key));
		if (key < node->key)
			return (search(node->left, key));
		return (NULL);
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::search(const K& key) const
	{
		return (_search(this, key));
	}

	template <class K, class V>
	static void	_insert(const node<K,V>*)
	{}
}