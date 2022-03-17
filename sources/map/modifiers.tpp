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
			node<K,V>::insert(&this->_root, kv.first, kv.second);
		if (result.second)
			_size++;
        return (ft::make_pair<iterator, bool>(iterator(result.first), result.second));
    }

	template <class K, class V, class C, class A>
	template <class I>
	void map<K,V,C,A>::insert(I first, I last)
	{
		for (I it = first; it != last; it++)
			node<K,V>::insert(it->first);
	}

	template <class K, class V, class C, class A>
	typename map<K,V,C,A>::iterator	map<K,V,C,A>::insert(iterator hint, const pair<K,V>& kv)
	{
		if (hint->slot())
			return (this->insert(kv));
		return (hint);
	}

	template <class K, class V, class C, class A>
	void map<K,V,C,A>::erase(iterator pos)
	{
		if (node<K,V>::erase(&this->_root, pos.slot()))
			this->_size--;
	}

	template < class K, class V, class C, class A >
	typename map<K,V,C,A>::size_type	map<K,V,C,A>::erase(const K& key)
	{
		if (node<K,V>::erase(&this->_root, key))
			return (1);
		return (0);
	}

	template <class K, class V, class C, class A>
	void map<K,V,C,A>::erase(iterator first, iterator last)
	{
		for (iterator it = first; it != last; it++)
			if (node<K,V>::erase(&_root, it->first))
				this->_size--;
	}

	template <class K, class V, class C, class A>
	void map<K,V,C,A>::swap(map& other)
	{
		map<K,V,C,A> tmp = *this;
		*this = other;
		other = tmp;
	}

	template <class K, class V, class C, class A>
	void	map<K,V,C,A>::swap(map& x, map& y)
	{
		x.swap(y);
	}
}