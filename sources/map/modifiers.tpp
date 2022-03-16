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
}