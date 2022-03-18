#pragma once

#include "map.hpp"

#include <stdexcept>
#include <iostream>

namespace ft
{
	template <class K, class V, class C, class A>
	V&	map<K,V,C,A>::at(const K& key)
	{
		node<K,V>* match = node<K,V>::search(this->_root, key);
		if (!match)
			throw std::out_of_range("map::at");
		return (match->value);
	}

	template <class K, class V, class C, class A>
    const V& map<K,V,C,A>::at(const K& key) const
    {
        node<K,V>* match = _root->search(this->_root, key);
        if (!match)
			throw std::out_of_range("map::at");
		return (match->value);
    }

	template <class K, class V, class C, class A>
	V&	map<K,V,C,A>::operator[](const K& key)
	{
		iterator it = this->insert(make_pair(key, V())).first;
		return (it.current()->value);
	}

	template <class K, class V, class C, class A>
	typename A::size_type	map<K,V,C,A>::count(const K& key) const
	{
		return (node<K,V>::search(this->_root, key) != NULL);
	}

	template <class K, class V, class C, class A>
	typename	map<K,V,C,A>::iterator	map<K,V,C,A>::find( const K& key )
	{
		node<K,V>* match = _root->search(this->_root, key);
		if (match)
			return (iterator(&this->_root, match));
		return (end());
	}

	template <class K, class V, class C, class A>
	typename	map<K,V,C,A>::const_iterator	map<K,V,C,A>::find(const K& key) const
	{
		node<K,V>* match = _root->search(this->_root, key);
		if (match)
			return (const_iterator(&this->_root, match));
		return (end());
	}

		template < class K, class V, class C, class A >
	typename map<K,V,C,A>::iterator map<K,V,C,A>::lower_bound( const K& key )
	{
		iterator	ite	= end();
		ite--;
		for (iterator	it	= begin(); it != ite; ite--)
		{
			node<K,V> *tmp = ite.current();
			if (tmp->key <= key)
				return (ite);
		}
		return (ite);
	}

	template < class K, class V, class C, class A >
	typename map<K,V,C,A>::const_iterator map<K,V,C,A>::lower_bound( const K& key ) const
	{
		return (const_iterator(this->lower_bound(key)));
	}

	template < class K, class V, class C, class A >
	typename map<K,V,C,A>::iterator map<K,V,C,A>::upper_bound( const K& key )
	{
		iterator	it	= begin();
		for (iterator	ite	= end(); it != ite; it++)
		{
			node<K,V> *tmp = it.current();
			if (tmp->key >= key)
				return (it);
		}
		return (it);
	}

	template < class K, class V, class C, class A >
	typename map<K,V,C,A>::const_iterator map<K,V,C,A>::upper_bound( const K& key ) const
	{
		return (const_iterator(this->upper_bound(key)));
	}

	template < class K, class V, class C, class A >
	pair	<typename map<K,V,C,A>::iterator ,typename map<K,V,C,A>::iterator> map<K,V,C,A>::equal_range(const K& key)
	{
		return (ft::make_pair(lower_bound(key), upper_bound(key)));
	}

	template < class K, class V, class C, class A >
	pair	<typename map<K,V,C,A>::const_iterator ,typename map<K,V,C,A>::const_iterator> map<K,V,C,A>::equal_range(const K& key) const
	{
		return (ft::make_pair(lower_bound(key), upper_bound(key)));
	}

}