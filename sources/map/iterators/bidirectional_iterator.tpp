#pragma once

#include "bidirectional_iterator.hpp"

namespace ft
{
	template<class K, class V, class C>
	bidirectional_iterator<K,V,C>::bidirectional_iterator(const C& comp):
		_slot(NULL),
        _comp(comp)
	{}

	template<class K, class V, class C>
	bidirectional_iterator<K,V,C>::~bidirectional_iterator(void)
	{}

	template<class K, class V, class C>
	bidirectional_iterator<K,V,C>::bidirectional_iterator(node<K,V>** slot, const C& comp):
		_slot(slot),
        _comp(comp)
	{}

	template<class K, class V, class C>
	bidirectional_iterator<K,V,C>::bidirectional_iterator(const bidirectional_iterator& from):
        _slot(from._slot),
        _comp(from._comp)
    {}

	template<class K, class V, class C>
	bidirectional_iterator<K,V,C>&	bidirectional_iterator<K,V,C>::operator=(const bidirectional_iterator& from)
	{
		if (this == &from)
			return (*this);
		this->_slot = from._slot;
		this->_comp = from._comp;
		return (*this);
	}

	template<class K, class V, class C>
	bidirectional_iterator<K,V,C>&	bidirectional_iterator<K,V,C>::operator++(void)
	{
		node<K,V>**  tmp = _slot;
		// TODO
		return (*this);
	}

	template<class K, class V, class C>
	bidirectional_iterator<K,V,C>	bidirectional_iterator<K,V,C>::operator++(int)
	{
		bidirectional_iterator old(*this);
		operator++();
		return (old);
	}

	template<class K, class V, class C>
	bidirectional_iterator<K,V,C>&	bidirectional_iterator<K,V,C>::operator--(void)
	{
		node<K,V>** tmp = _slot;
		// TODO
		return (*this);
	}

	template<class K, class V, class C>
	bidirectional_iterator<K,V,C>	bidirectional_iterator<K,V,C>::operator--(int)
	{
		bidirectional_iterator old(*this);
		operator--();
		return (old);
	}

	template<class K, class V, class C>
	bool	bidirectional_iterator<K,V,C>::operator==(const bidirectional_iterator& other) const
	{
		if ((*this->_slot)->key != (*other._slot)->key)
			return (false);
		if ((*this->_slot)->value != (*other._slot)->value)
			return (false);
		return (true);
	}

	template<class K, class V, class C>
	bool	bidirectional_iterator<K,V,C>::operator!=(const bidirectional_iterator& other) const
	{
		return (!(this == other));
	}

	template<class K, class V, class C>
	pair<K,V>	bidirectional_iterator<K,V,C>::operator*(void) const
	{
		return (ft::make_pair((*this->_slot)->key, (*this->_slot)->value));
	}

	template<class K, class V, class C>
	pair<K,V>	bidirectional_iterator<K,V,C>::operator->(void) const
	{
		return (ft::make_pair((*this->_slot)->key, (*this->_slot)->value));
	}
}