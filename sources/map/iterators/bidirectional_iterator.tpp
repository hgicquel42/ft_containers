#pragma once

#include "bidirectional_iterator.hpp"

namespace ft
{
	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>::map_bidirectional_iterator(const C& comp):
		_slot(NULL),
        _comp(comp)
	{}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>::~map_bidirectional_iterator(void)
	{}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>::map_bidirectional_iterator(node<K,V>** slot, const C& comp):
		_slot(slot),
        _comp(comp)
	{}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>::map_bidirectional_iterator(const map_bidirectional_iterator& from):
        _slot(from._slot),
        _comp(from._comp)
    {}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>&	map_bidirectional_iterator<K,V,C>::operator=(const map_bidirectional_iterator& from)
	{
		if (this == &from)
			return (*this);
		this->_slot = from._slot;
		this->_comp = from._comp;
		return (*this);
	}

	template<class K, class V, class C>
	map_bidirectional_iterator<K,V,C>&	map_bidirectional_iterator<K,V,C>::operator++(void)
	{
		this->_slot = node<K,V>::next(this->_slot);
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
		this->_slot = node<K,V>::previous(this->_slot);
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
		return (this->_slot == other._slot);
	}

	template<class K, class V, class C>
	bool	map_bidirectional_iterator<K,V,C>::operator!=(const map_bidirectional_iterator& other) const
	{
		return (!(*this == other));
	}

	template<class K, class V, class C>
	pair<K,V>	map_bidirectional_iterator<K,V,C>::operator*(void) const
	{
		return (ft::make_pair<K,V>((*this->_slot)->key, (*this->_slot)->value));
	}

	template<class K, class V, class C>
	pair<K,V>	map_bidirectional_iterator<K,V,C>::operator->(void) const
	{
		return (ft::make_pair<K,V>((*this->_slot)->key, (*this->_slot)->value));
	}

	template<class K, class V, class C>
	node<K,V>**	map_bidirectional_iterator<K,V,C>::slot(void) const
	{
		return (this->_slot);
	}
}