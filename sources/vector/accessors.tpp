#pragma once

#include <stdexcept>

#include "vector.hpp"

namespace ft
{
	template <class T, class A>
	typename A::reference	vector<T,A>::front(void)
	{
		return (*this->_start);
	}

	template <class T, class A>
	typename A::const_reference	vector<T,A>::front(void) const
	{
		return (*this->_start);
	}

	template <class T, class A>
	typename A::reference	vector<T,A>::back(void)
	{
		return (*(this->_start + this->_size - 1));
	}

	template <class T, class A>
	typename A::const_reference	vector<T,A>::back(void) const
	{
		return (*(this->_start + this->_size - 1));
	}

	template <class T, class A>
	typename A::reference	vector<T,A>::at(size_type index)
	{
		if (index >= this->_size)
			throw std::out_of_range("vector::at");
		return (*(this->_start + index));
	}

	template <class T, class A>
	typename A::const_reference	vector<T,A>::at(size_type index) const
	{
		if (index >= this->_size)
			throw std::out_of_range("vector::at");
		return (*(this->_start + index));
	}

	template <class T, class A>
	typename A::reference	vector<T,A>::operator[](size_type index)
	{
		return (*(this->_start + index));
	}

	template <class T, class A>
	typename A::const_reference	vector<T,A>::operator[](size_type index) const
	{
		return (*(this->_start + index));
	}
}