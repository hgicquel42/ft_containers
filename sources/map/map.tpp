#pragma once

#include "map.hpp"

namespace ft
{
	template <class K, class V, class C, class A>
	map<K,V,C,A>::map(void):
		_root(NULL),
		_comp(C()),
		_alloc(A()),
		_size(0)
	{}
	
	template <class K, class V, class C, class A>
	map<K,V,C,A>::map(const C& comp, const A& alloc):
		_root(NULL),
		_comp(comp),
		_alloc(alloc),
		_size(0)
	{}

	template <class K, class V, class C, class A>
	map<K,V,C,A>::~map(void)
	{
		this->clear();
	}

	template <class K, class V, class C, class A>
	map<K,V,C,A>::map(const map& from):
		_root(NULL),
		_comp(from._comp),
		_alloc(from._alloc),
		_size(0)
	{
		this->insert(from.begin(), from.end());
	}

	template <class K, class V, class C, class A>
	template<class I>
	map<K,V,C,A>::map(I first, I last, const C& comp, const A& alloc):
		_comp(comp),
		_alloc(alloc),
		_size(0)
	{
		this->insert(first, last);
	}

	template <class K, class V, class C, class A>
	map<K,V,C,A>&	map<K,V,C,A>::operator=(const map& from)
	{
		if (this == &from)
			return (*this);
		this->clear();
		this->insert(from.begin(), from.end());
		this->_comp = from._comp;
		this->_alloc = from._alloc;
		this->_size = from._size;
		return (*this);
	}

	template <class K, class V, class C, class A>
	A	map<K,V,C,A>::get_allocator(void) const
	{
		return (this->_alloc);
	}

	template <class K, class V, class C, class A>
	C	map<K,V,C,A>::key_comp(void) const
	{
		return (this->_comp);
	}

	template <class K, class V, class C, class A>
	typename map<K,V,C,A>::value_compare	map<K,V,C,A>::value_comp(void) const
	{
		return (value_compare(this->_comp));
	}

	// template <class K, class V, class C, class A>
	// void	map<K,V,C,A>::print(void) const
	// {
	// 	node<K,V>::print(this->_root);
	// }
}