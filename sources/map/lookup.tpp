#pragma once

#include "map.hpp"

#include <stdexcept>

namespace ft
{
	template <class K, class V, class C, class A>
	V&	map<K,V,C,A>::at(const K& key)
	{
		node<K,V> match = node<K,V>::search(this->_root, key);
		if (!match)
			throw std::out_of_range("map::at");
		return (match->value);
	}

	template <class K, class V, class C, class A>
	typename A::size_type	map<K,V,C,A>::count(const K& key) const
	{
		return (node<K,V>::search(this->_root, key) != NULL);
	}
}