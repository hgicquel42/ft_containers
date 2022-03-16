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
	bool	node<K,V>::isblack(node* slot)
	{
		return (slot && slot->color == NBLACK);
	}

	template <class K, class V>
	bool	node<K,V>::isred(node* slot)
	{
		return (slot && slot->color == NRED);
	}

	template <class K, class V>
	node<K,V>**	node<K,V>::minimum(node** slot)
	{
		if (!(*slot)->left)
			return (slot);
		return (minimum(&(*slot)->left));
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
	node<K,V>**	node<K,V>::search(node** root, const K& key)
	{
		if (!root)
			return (NULL);
		if (!*root)
			return (root);
		if (key == *root->key)
			return (root);
		if (key > *root->key)
			return (search(&(*root)->right, key));
		if (key < *root->key)
			return (search(&(*root)->left, key));
		return (root);
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
		return (root);
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

	template <class K, class V>
	void	node<K,V>::lrotate(node** slot)
	{
		node* current = *slot;
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
	void	node<K,V>::rrotate(node** slot)
	{
		node* current = *slot;
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
	void	node<K,V>::insert(node** root, const K& key, const V& value)
	{
		node* parent = NULL;

		node** slot = spot(&parent, root, key);
		if (!slot) return ;

		cout << "insert\n";

		if (!*slot) {
			*slot = new node<K,V>(parent, key, value, NRED);
			insertf(root, slot);
			return ;
		}

		(*slot)->value = value;
	}

	/**
	 * @brief Fix after insert (recursive)
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param slot 
	 */
	template <class K, class V>
	void	node<K,V>::insertf(node** root, node** slot)
	{
		if (!slot || !*slot) return ;

		node* current = *slot;
		node* parent = current->parent;

		if (!parent) {
			current->color = NBLACK;
			return ;
		}

		if (parent->color == NBLACK) {
			return ;
		}

		node* gparent = parent->parent;

		if (!gparent) {
			parent->color = NBLACK;
			return ;
		}

		node* uncle = *node::uncle(current);

		if (uncle && uncle->color == NRED) {
			parent->color = NBLACK;
			gparent->color = NRED;
			uncle->color = NBLACK;
			insertf(root, node::slot(root, gparent));
			return ;
		}

		else if (parent == gparent->left) {
			if (current == parent->right) {
				lrotate(node::slot(root, parent));
				parent = current;
			}
			rrotate(node::slot(root, gparent));
			parent->color = NBLACK;
			gparent->color = NRED;
			return ;
		}

		else {
			if (current == parent->left) {
				rrotate(node::slot(root, parent));
				parent = current;
			}

			lrotate(node::slot(root, gparent));
			parent->color = NBLACK;
			gparent->color = NRED;
			return ;
		}
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
	void	node<K,V>::erase(node** root, const K& key)
	{
		node* parent = NULL;

		node** slot = spot(&parent, root, key);
		if (slot && *slot) erase(slot);
	}

	/**
	 * @brief Erase by slot
	 * 
	 * @tparam K 
	 * @tparam V 
	 * @param slot 
	 */
	template <class K, class V>
	void	node<K,V>::erase(node** root, node** slot)
	{
		if (!slot || !*slot) return ;

		node* current = *slot;

		if (current->left && current->right) {
			node** min = minimum(&current->right);
			current->key = (*min)->key;
			current->value = (*min)->value;
			erase(root, min);
			return ;
		}

		bool color = current->color;

		if (current->right) {
			node* next = current->right;
			next->parent = current->parent;
			delete current;
			*slot = next;
		} else if (current->left) {
			node* next = current->left;
			next->parent = current->parent;
			delete current;
			*slot = next;
		} else {
			delete current;
			*slot = NULL;
		}

		if (!*slot)
			return ;
		if (color == NRED)
			return ;
		erasef(root, slot);
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
	void	node<K,V>::erasef(node** root, node** slot)
	{
		if (!slot || !*slot) return ;

		node* current = *slot;
		node* parent = current->parent;

		if (!parent) {
			current->color = NBLACK;
			return ;
		}

		node* sibling = *node::sibling(current);

		if (sibling->color == NRED) {
			sibling->color = NBLACK;
			parent->color = NRED;
			
			if (current == parent->left)
				lrotate(node::slot(root, parent));
			else if (current == parent->right)
				rrotate(node::slot(root, parent));
			sibling = *node::sibling(current);
		}

		if (isblack(sibling->left) && isblack(sibling->right))
		{
			sibling->color = NRED;

			if (parent->color == NRED)
				parent->color = NBLACK;
			else
				erasef(root, node::slot(root, parent));
			return ;
		}

		if (current == parent->left && isblack(sibling->right)) {
			sibling->left->color = NBLACK;
			sibling->color = NRED;
			rrotate(node::slot(root, sibling));
			sibling = parent->right;
		}

		if (current == parent->right && isblack(sibling->left)) {
			sibling->right->color = NBLACK;
			sibling->color = NRED;
			lrotate(node::slot(root, sibling));
			sibling = parent->left;
		}

		sibling->color = parent->color;
		parent->color = NBLACK;
		if (current == parent->left) {
			if (sibling)
				sibling->right->color = NBLACK;
			lrotate(node::slot(root, parent));
		} else {
			if (sibling)
				sibling->left->color = NBLACK;
			rrotate(node::slot(root, parent));
		}
	}
}