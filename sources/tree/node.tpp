#pragma once

#include <iostream>

#include "node.hpp"
#include "pair.hpp"

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
	node<K,V>::node(node* parent, const K& key, const V& value, bool color):
		key(key),
		value(value),
		parent(parent),
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
	node<K,V>*	node<K,V>::sibling(void)
	{
		if (!this->parent)
			return (NULL);
		if (this == this->parent->left)
			return (this->parent->right);
		if (this == this->parent->right)
			return (this->parent->left);
		return (NULL);
	}

	template <class K, class V>
	node<K,V>*	node<K,V>::uncle(void)
	{
		if (!this->parent)
			return (NULL);
		return (this->parent->sibling());
	}

	template <class K, class V>
	node<K,V>*&	node<K,V>::minimum(node*& root)
	{
		if (!root->left)
			return (root);
		return (minimum(root->left));
	}

	template <class K, class V>
	void	node<K,V>::print(const node* root, const string& prefix, int position)
	{
		cout << prefix;

		if (position == -1)
			cout << "|---";
		else if (position == 1)
			cout << "└---";

		if (!root) {
			cout << "null\n";
			return ;
		}

		if (root->color == NRED)
			cout << RED;
		cout << "[" << root->key << "]" << RESET;
		cout << " = " << root->value;
		// Uncomment to show parent address and current address
		// cout << " (" << root->parent << " -> " << root << ")";
		cout << "\n";

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
		if (key > root->key)
			return (search(root->right, key));
		if (key < root->key)
			return (search(root->left, key));
		return (NULL);
	}

	template <class K, class V>
	void	node<K,V>::lrotate(node*& root)
	{
		if (!root || !root->right)
			return ;
		node* x = root->right;
		node* y = x->left;
		x->left = root;
		x->parent = root->parent;
		root->right = y;
		root->parent = x;
		if (y)
			y->parent = root;
		root = x;
	}

	template <class K, class V>
	void	node<K,V>::rrotate(node*& root)
	{
		if (!root || !root->left)
			return ;
		node* x = root->left;
		node* y = x->right;
		x->right = root;
		x->parent = root->parent;
		root->left = y;
		root->parent = x;
		if (y)
			y->parent = root;
		root = x;
	}

	/**
	 * @brief Find a spot for that key and save its parent
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param parent 
	 * @param root 
	 * @param key 
	 * @return node<K,V>*& 
	 */
	template <class K, class V>
	node<K,V>*&	node<K,V>::spot(node*& parent, node*& root, const K& key)
	{
		if (!root)
			return (root);
		parent = root;
		if (key == root->key)
			return (root);
		if (key < root->key)
			return (spot(parent, root->left, key));
		if (key > root->key)
			return (spot(parent, root->right, key));
		return (root);
	}

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
	void	node<K,V>::insert(node*& root, const K& key, const V& value)
	{
		node* parent = NULL;

		node*& slot = spot(parent, root, key);

		if (!slot) {
			slot = new node<K,V>(parent, key, value, NRED);
			node::insertf(slot);
		}

		slot->value = value;
	}

	/**
	 * @brief Fix after insert (recursive)
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param slot 
	 */
	template <class K, class V>
	void	node<K,V>::insertf(node* slot)
	{
		node* parent = slot->parent;

		if (!parent) {
			slot->color = NBLACK;
			return ;
		}

		if (parent->color == NBLACK) {
			return ;
		}

		node* uncle = slot->uncle();

		if (uncle && uncle->color == NRED) {
			parent->color = NBLACK;
			uncle->color = NBLACK;
			parent->parent->color = NRED;
			insertf(parent->parent);
			return ;
		}

		if (parent == parent->parent->left) {
			if (slot == parent->right) {
				lrotate(parent);
				parent = slot;
			}

			rrotate(parent->parent);
			parent->color = NBLACK;
			parent->parent->color = NRED;
		}

		if (parent == parent->parent->right) {
			if (slot == parent->left) {
				rrotate(parent);
				parent = slot;
			}

			lrotate(parent->parent);
			parent->color = NBLACK;
			parent->parent->color = NRED;
		}
	}

	/**
	 * @brief Erase by slot
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param slot 
	 */
	template <class K, class V>
	void	node<K,V>::erase(node*& slot)
	{
		node* parent = slot->parent;

		if (slot->left && slot->right) {
			node*& min = minimum(slot);
			slot->key = min->key;
			slot->value = min->value;
			erase(min);
			return ;
		}

		bool color = slot->color;

		if (slot->right) {
			node* next = slot->right;
			delete slot;
			slot = next;
			slot->parent = parent;
		} else if (slot->left) {
			node* next = slot->left;
			delete slot;
			slot = next;
			slot->parent = parent;
		} else {
			delete slot;
			slot = NULL;
		}

		erasef(parent, slot, color);
	}

	/**
	 * @brief Erase by key
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param root 
	 * @param key 
	 */
	template <class K, class V>
	void	node<K,V>::erase(node*& root, const K& key)
	{
		node* parent = NULL;

		node*& slot = spot(parent, root, key);
		if (!slot)
			return ;
		erase(slot);
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
	void	node<K,V>::erasef(node* parent, node* slot, bool color)
	{
		(void) (parent && slot && color);
		// TODO https://www.happycoders.eu/algorithms/red-black-tree-java/
		// https://github.com/SvenWoltmann/binary-tree/blob/main/src/main/java/eu/happycoders/binarytree/RedBlackTree.java#L252
	}
}