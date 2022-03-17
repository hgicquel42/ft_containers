#pragma once

#include "map.hpp"

namespace ft
{
	template <class K, class V, class C, class A>
	void	map<K,V,C,A>::clear(void)
	{
		while (this->_root)
			node<K,V>::erase(&this->_root, &this->_root);
		this->_size = 0;
	}

	template < class K, class V, class C, class A >
    pair<typename map<K,V,C,A>::iterator, bool>	map<K,V,C,A>::insert(const pair<K,V>& kv)
    {
        pair<node<K,V>**, bool> result =
			node<K,V>::insert(&_root, kv.first, kv.second);
		if (result.second)
			_size++;
        return (ft::make_pair(iterator(result.first), result.second));
    }
}