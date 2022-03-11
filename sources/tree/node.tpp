#pragma once

#include "node.hpp"

namespace ft
{
	template <class K, class V>
	node<K,V>::node(void)
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
	node<K,V>&	node<K,V>::node(const node& from)
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
	node<K,V>::node(const K& key, const V& value, node* left, node* right, bool color):
		key(key),
		value(value),
		left(left),
		right(right),
		color(color)
	{}

	template <class K, class V>
	node<K,V>::search(const K& key)
	{
		if (this->key == key)
			return (this);
		if (this->key < key)
			return (this->right->search());
			//TODO
	}
}