#pragma once

#include "map.hpp"

namespace ft
{
	template <class K, class V, class C, class A>
	bool	map<K,V,C,A>::empty(void) const
	{
		return (this->_size == 0);
	}

	template <class K, class V, class C, class A>
	typename A::size_type	map<K,V,C,A>::size(void) const
	{
		return (this->_size);
	}

	template <class K, class V, class C, class A>
	typename A::size_type	map<K,V,C,A>::max_size(void) const
	{
		return (this->_alloc.max_size());
	}
}