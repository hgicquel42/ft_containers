#pragma once

#include "map_reverse_iterator.hpp"

namespace ft
{
	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>::map_reverse_iterator(const C& comp):
		_node(),
        _comp(comp)
	{}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>::~map_reverse_iterator(void)
	{}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>::map_reverse_iterator(node<K,V>** node_p, const C& comp):
		_node(node_p),
        _comp(comp)
	{}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>::map_reverse_iterator(const map_reverse_iterator& from):
		_node(from._node),
        _comp(from._comp)
	{}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>&	map_reverse_iterator<K,V,C>::operator=(const map_reverse_iterator& from)
	{
		if (this == &from)
			return (*this);
		this->_node = from._node;
		this->_comp = from._comp;
		return (*this);
	}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>&	map_reverse_iterator<K,V,C>::operator++(void)
	{
		node<K,V>**  tmp = _node;

		

		return (*this);
	}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>	map_reverse_iterator<K,V,C>::operator++(int)
	{
		map_reverse_iterator old(*this);
		operator++();
		return (old);
	}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>&	map_reverse_iterator<K,V,C>::operator--(void)
	{
		node<K,V>** tmp = _node;


		return (*this);
	}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>	map_reverse_iterator<K,V,C>::operator--(int)
	{
		map_reverse_iterator old(*this);
		operator--();
		return (old);
	}

	template<class K, class V, class C>
	bool	map_reverse_iterator<K,V,C>::operator==(const map_reverse_iterator& other) const
	{
		return ((*this->_node)->key == (*other._node)->key && (*this->_node)->value == (*other._node)->value);
	}

	template<class K, class V, class C>
	bool	map_reverse_iterator<K,V,C>::operator!=(const map_reverse_iterator& other) const
	{
		return (!(this == other));
	}

	template<class K, class V, class C>
	pair<K,V>	map_reverse_iterator<K,V,C>::operator*(void) const
	{
		return (ft::make_pair((*this->_node)->key, (*this->_node)->value));
	}

	template<class K, class V, class C>
	pair<K,V>	map_reverse_iterator<K,V,C>::operator->(void) const
	{
		return (ft::make_pair((*this->_node)->key, (*this->_node)->value));
	}
}