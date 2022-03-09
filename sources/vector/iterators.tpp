#pragma once

#include "vector.hpp"

namespace ft 
{
	template<class T, class A>
	random_access_iterator<T>	vector<T,A>::begin(void)
	{
		return (random_access_iterator<T>(this->_start));
	}

	template<class T, class A>
	random_access_iterator<const T>	vector<T,A>::begin(void) const
	{
		return (random_access_iterator<const T>(this->_start));
	}

	template<class T, class A>
	random_access_iterator<T>	vector<T,A>::end(void)
	{
		return (random_access_iterator<T>(this->_start + this->_size));
	}

	template<class T, class A>
	random_access_iterator<const T>	vector<T,A>::end(void) const
	{
		return (random_access_iterator<const T>(this->_start + this->_size));
	}

	template<class T, class A>
	reverse_iterator<T>	vector<T,A>::rbegin(void)
	{
		return (ft::reverse_iterator<T>(this->_start));
	}

	template<class T, class A>
	reverse_iterator<const T>	vector<T,A>::rbegin(void) const
	{
		return (ft::reverse_iterator<const T>(this->_start));
	}

	template<class T, class A>
	reverse_iterator<T>	vector<T,A>::rend(void)
	{
		return (ft::reverse_iterator<T>(this->_start + this->_size));
	}

	template<class T, class A>
	reverse_iterator<const T>	vector<T,A>::rend(void) const
	{
		return (ft::reverse_iterator<const T>(this->_start + this->_size));
	}
}
