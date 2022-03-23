#pragma once

#include "const_bidirectional_iterator.hpp"

namespace ft
{
	template<class K, class V, class C>
	const_map_bidirectional_iterator<K,V,C>::const_map_bidirectional_iterator(const C& comp):
		_root(NULL),
		_node(NULL),
        _comp(comp)
	{}

	template<class K, class V, class C>
	const_map_bidirectional_iterator<K,V,C>::~const_map_bidirectional_iterator(void)
	{}

	template<class K, class V, class C>
	const_map_bidirectional_iterator<K,V,C>::const_map_bidirectional_iterator(const node<K,V>*const* root, const node<K,V>* current, const C& comp):
		_root(root),
		_node(current),
        _comp(comp)
	{}

	template<class K, class V, class C>
	const_map_bidirectional_iterator<K,V,C>::const_map_bidirectional_iterator(const const_map_bidirectional_iterator& from):
		_root(from._root),
        _node(from._node),
        _comp(from._comp)
    {}

	template<class K, class V, class C>
	const_map_bidirectional_iterator<K,V,C>&	const_map_bidirectional_iterator<K,V,C>::operator=(const const_map_bidirectional_iterator& from)
	{
		if (this == &from)
			return (*this);
		this->_root = from._root;
		this->_node = from._node;
		this->_comp = from._comp;
		return (*this);
	}

	template<class K, class V, class C>
	const_map_bidirectional_iterator<K,V,C>&	const_map_bidirectional_iterator<K,V,C>::operator++(void)
	{
		this->_node = node<K,V>::next(this->_node);
		return (*this);
	}

	template<class K, class V, class C>
	const_map_bidirectional_iterator<K,V,C>	const_map_bidirectional_iterator<K,V,C>::operator++(int)
	{
		const_map_bidirectional_iterator old(*this);
		operator++();
		return (old);
	}

	template<class K, class V, class C>
	const_map_bidirectional_iterator<K,V,C>&	const_map_bidirectional_iterator<K,V,C>::operator--(void)
	{
		this->_node = node<K,V>::previous(this->_root, this->_node);
		return (*this);
	}

	template<class K, class V, class C>
	const_map_bidirectional_iterator<K,V,C>	const_map_bidirectional_iterator<K,V,C>::operator--(int)
	{
		const_map_bidirectional_iterator old(*this);
		operator--();
		return (old);
	}

	template<class K, class V, class C>
	bool	const_map_bidirectional_iterator<K,V,C>::operator==(const const_map_bidirectional_iterator& other) const
	{
		return (this->_node == other._node);
	}

	template<class K, class V, class C>
	bool	const_map_bidirectional_iterator<K,V,C>::operator!=(const const_map_bidirectional_iterator& other) const
	{
		return (this->_node != other._node);
	}

	template<class K, class V, class C>
	pair<K,V>	const_map_bidirectional_iterator<K,V,C>::operator*(void) const
	{
		return (ft::make_pair<K,V>(this->_node->key, this->_node->value));
	}

	template<class K, class V, class C>
	pair<K,V>	const_map_bidirectional_iterator<K,V,C>::operator->(void) const
	{
		return (ft::make_pair<K,V>(this->_node->key, this->_node->value));
	}

	template<class K, class V, class C>
	const node<K,V>*	const_map_bidirectional_iterator<K,V,C>::current(void) const
	{
		return (this->_node);
	}
}