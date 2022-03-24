#pragma once

#include "map.hpp"

namespace ft
{
	template <class K, class V, class C, class A>
	void	map<K,V,C,A>::clear(void)
	{
		while (this->_root)
			node<K,V>::erase(&this->_root, this->_root);
		this->_size = 0;
	}

	template < class K, class V, class C, class A >
    pair<typename map<K,V,C,A>::iterator, bool>	map<K,V,C,A>::insert(const pair<K,V>& kv)
    {
        pair<node<K,V>*, bool> result =
			node<K,V>::template insert<C>(&this->_root, kv.first, kv.second);
		iterator it = iterator(&this->_root, result.first);
		if (result.second)
			_size++;
        return (ft::make_pair<iterator, bool>(it, result.second));
    }

	template <class K, class V, class C, class A>
	template <class I>
	void map<K,V,C,A>::insert(I first, I last)
	{
		for (I it = first; it != last; it++)
			this->insert(*it);
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
		if (node<K,V>::erase(&this->_root, pos.current()))
			this->_size--;
	}

	template < class K, class V, class C, class A >
	typename map<K,V,C,A>::size_type	map<K,V,C,A>::erase(const K& key)
	{
		if (!node<K,V>::template erase<C>(&this->_root, key))
			return (0);
		this->_size--;
		return (1);
	}

	template <class K, class V, class C, class A>
	void map<K,V,C,A>::erase(iterator first, iterator last)
	{
		for (iterator it = first; it != last; it++)
			if (node<K,V>::erase(&this->_root, it.current()))
				this->_size--;
	}

	template <class K, class V, class C, class A>
	void map<K,V,C,A>::swap(map& other)
	{
		node<K,V>*	temp_root = this->_root;
		C			temp_comp = this->_comp;
		A			temp_alloc = this->_alloc;
		size_type	temp_size = this->_size;

		this->_root = other._root;
		this->_comp = other._comp;
		this->_alloc = other._alloc;
		this->_size = other._size;

		other._root = temp_root;
		other._comp = temp_comp;
		other._alloc = temp_alloc;
		other._size = temp_size;
	}

	template <class K, class V, class C, class A>
	void	swap(map<K,V,C,A>& x, map<K,V,C,A>& y)
	{
		x.swap(y);
	}
}