#pragma once

#include "reverse_iterator.hpp"

namespace ft
{
	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>::map_reverse_iterator(const C& comp):
		_slot(),
        _comp(comp)
	{}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>::~map_reverse_iterator(void)
	{}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>::map_reverse_iterator(node<K,V>** slot, const C& comp):
		_slot(slot),
        _comp(comp)
	{}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>::map_reverse_iterator(const map_reverse_iterator& from):
		_slot(from._slot),
        _comp(from._comp)
	{}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>&	map_reverse_iterator<K,V,C>::operator=(const map_reverse_iterator& from)
	{
		if (this == &from)
			return (*this);
		this->_slot = from._slot;
		this->_comp = from._comp;
		return (*this);
	}

	template<class K, class V, class C>
	map_reverse_iterator<K,V,C>&	map_reverse_iterator<K,V,C>::operator++(void)
	{
		node<K,V>**  tmp = _slot;

		

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
		node<K,V>** tmp = _slot;


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
		return ((*this->_slot)->key == (*other._slot)->key && (*this->_slot)->value == (*other._slot)->value);
	}

	template<class K, class V, class C>
	bool	map_reverse_iterator<K,V,C>::operator!=(const map_reverse_iterator& other) const
	{
		return (!(this == other));
	}

	template<class K, class V, class C>
	pair<K,V>	map_reverse_iterator<K,V,C>::operator*(void) const
	{
		return (ft::make_pair((*this->_slot)->key, (*this->_slot)->value));
	}

	template<class K, class V, class C>
	pair<K,V>	map_reverse_iterator<K,V,C>::operator->(void) const
	{
		return (ft::make_pair((*this->_slot)->key, (*this->_slot)->value));
	}
}