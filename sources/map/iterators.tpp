#pragma once

#include "map.hpp"

namespace ft
{
	template < class K, class V, class C, class A >
    typename map<K,V,C,A>::iterator   map<K,V,C,A>::begin(void)
    {
        return (iterator(&this->_root, this->_root->minimum(this->_root)));
    }

    template < class K, class V, class C, class A >
    typename map<K,V,C,A>::const_iterator   map<K,V,C,A>::begin(void) const
    {
        return (const_iterator(&this->_root, this->_root->minimum(this->_root)));
    }

    template < class K, class V, class C, class A >
    typename map<K,V,C,A>::reverse_iterator   map<K,V,C,A>::rbegin(void)
    {
        return (reverse_iterator(&this->_root, this->_root->minimum(this->_root)));
    }

    template < class K, class V, class C, class A >
    typename map<K,V,C,A>::const_reverse_iterator  map<K,V,C,A>::rbegin(void) const
    {
        return (const_reverse_iterator(&this->_root, this->_root->minimum(this->_root)));
    }

    template < class K, class V, class C, class A >
    typename map<K,V,C,A>::iterator   map<K,V,C,A>::end(void)
    {
        return (iterator(&this->_root, NULL));
    }

    template < class K, class V, class C, class A >
    typename map<K,V,C,A>::const_iterator   map<K,V,C,A>::end(void) const
    {
        return (const_iterator(&this->_root, NULL));
    }

    template < class K, class V, class C, class A >
    typename map<K,V,C,A>::reverse_iterator   map<K,V,C,A>::rend(void)
    {
        return (reverse_iterator(&this->_root, NULL));
    }

    template < class K, class V, class C, class A >
    typename map<K,V,C,A>::const_reverse_iterator  map<K,V,C,A>::rend(void) const
    {
        return (const_reverse_iterator(&this->_root, NULL));
    }
}