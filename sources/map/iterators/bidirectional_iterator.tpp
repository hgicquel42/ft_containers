#pragma once

#include "bidirectional_iterator.hpp"

namespace ft
{
	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>::map_bidirectional_iterator(const C& comp):
		_root(NULL),
		_node(NULL),
        _comp(comp)
	{}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>::~map_bidirectional_iterator(void)
	{}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>::map_bidirectional_iterator(node<K,V>*const* root, node<K,V>* current, const C& comp):
		_root(root),
		_node(current),
        _comp(comp)
	{}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>::map_bidirectional_iterator(const map_bidirectional_iterator& from):
		_root(from._root),
        _node(from._node),
        _comp(from._comp)
    {}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>&	map_bidirectional_iterator<K,V,C>::operator=(const map_bidirectional_iterator& from)
	{
		if (this == &from)
			return (*this);
		this->_root = from._root;
		this->_node = from._node;
		this->_comp = from._comp;
		return (*this);
	}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>&	map_bidirectional_iterator<K,V,C>::operator++(void)
	{
		this->_node = node<K,V>::next(this->_node);
		return (*this);
	}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>	map_bidirectional_iterator<K,V,C>::operator++(int)
	{
		map_bidirectional_iterator old(*this);
		operator++();
		return (old);
	}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>&	map_bidirectional_iterator<K,V,C>::operator--(void)
	{
		this->_node = node<K,V>::previous(this->_root, this->_node);
		return (*this);
	}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>	map_bidirectional_iterator<K,V,C>::operator--(int)
	{
		map_bidirectional_iterator old(*this);
		operator--();
		return (old);
	}

	template<class K, class V, class C>
	bool	map_bidirectional_iterator<K,V,C>::operator==(const map_bidirectional_iterator& other) const
	{
		return (this->_node == other._node);
	}

	template<class K, class V, class C>
	bool	map_bidirectional_iterator<K,V,C>::operator!=(const map_bidirectional_iterator& other) const
	{
		return (this->_node != other._node);
	}

	template<class K, class V, class C>
	pair<K,V>	map_bidirectional_iterator<K,V,C>::operator*(void) const
	{
		return (ft::make_pair<K,V>(this->_node->key, this->_node->value));
	}

	template<class K, class V, class C>
	pair<K,V>	map_bidirectional_iterator<K,V,C>::operator->(void) const
	{
		return (ft::make_pair<K,V>(this->_node->key, this->_node->value));
	}

	template<class K, class V, class C>
	node<K,V>*	map_bidirectional_iterator<K,V,C>::current(void) const
	{
		return (this->_node);
	}
}