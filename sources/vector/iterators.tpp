#pragma once

#include "vector.hpp"

namespace ft 
{
	template<class T, class A>
	vector_random_access_iterator<T>	vector<T,A>::begin(void)
	{
		return (vector_random_access_iterator<T>(this->_start));
	}

	template<class T, class A>
	vector_random_access_iterator<const T>	vector<T,A>::begin(void) const
	{
		return (vector_random_access_iterator<const T>(this->_start));
	}

	template<class T, class A>
	vector_random_access_iterator<T>	vector<T,A>::end(void)
	{
		return (vector_random_access_iterator<T>(this->_start + this->_size));
	}

	template<class T, class A>
	vector_random_access_iterator<const T>	vector<T,A>::end(void) const
	{
		return (vector_random_access_iterator<const T>(this->_start + this->_size));
	}

	template<class T, class A>
	vector_reverse_iterator<T>	vector<T,A>::rbegin(void)
	{
		return (ft::vector_reverse_iterator<T>(this->_start));
	}

	template<class T, class A>
	vector_reverse_iterator<const T>	vector<T,A>::rbegin(void) const
	{
		return (ft::vector_reverse_iterator<const T>(this->_start));
	}

	template<class T, class A>
	vector_reverse_iterator<T>	vector<T,A>::rend(void)
	{
		return (ft::vector_reverse_iterator<T>(this->_start + this->_size));
	}

	template<class T, class A>
	vector_reverse_iterator<const T>	vector<T,A>::rend(void) const
	{
		return (ft::vector_reverse_iterator<const T>(this->_start + this->_size));
	}
}
