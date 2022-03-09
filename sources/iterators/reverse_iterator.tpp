#pragma once

#include "reverse_iterator.hpp"

namespace ft
{
	template<class T>
	reverse_iterator<T>::reverse_iterator(void):
		_pointer(NULL)
	{}

	template<class T>
	reverse_iterator<T>::~reverse_iterator(void)
	{}

	template<class T>
	reverse_iterator<T>::reverse_iterator(T* pointer):
		_pointer(pointer)
	{}

	template<class T>
	reverse_iterator<T>::reverse_iterator(const reverse_iterator& from):
		_pointer(from._pointer)
	{}

	template<class T>
	reverse_iterator<T>&	reverse_iterator<T>::operator=(const reverse_iterator& from)
	{
		if (this == &from)
			return (*this);
		this->_pointer = from._pointer;
		return (*this);
	}

	template<class T>
	reverse_iterator<T>&	reverse_iterator<T>::operator++(void)
	{
		this->_pointer--;
		return (*this);
	}

	template<class T>
	reverse_iterator<T>	reverse_iterator<T>::operator++(int)
	{
		reverse_iterator old(*this);
		this->_pointer--;
		return (old);
	}

	template<class T>
	reverse_iterator<T>&	reverse_iterator<T>::operator--(void)
	{
		this->_pointer++;
		return (*this);
	}

	template<class T>
	reverse_iterator<T>	reverse_iterator<T>::operator--(int)
	{
		reverse_iterator old(*this);
		this->_pointer++;
		return (old);
	}

	template<class T>
	bool	reverse_iterator<T>::operator==(const reverse_iterator& other) const
	{
		return (this->_pointer == other._pointer);
	}

	template<class T>
	bool	reverse_iterator<T>::operator!=(const reverse_iterator& other) const
	{
		return (this->_pointer != other._pointer);
	}

	template<class T>
	T&	reverse_iterator<T>::operator*(void) const
	{
		return (*this->_pointer);
	}

	template<class T>
	T*	reverse_iterator<T>::operator->(void) const
	{
		return (this->_pointer);
	}
}