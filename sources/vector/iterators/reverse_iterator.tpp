#pragma once

#include "reverse_iterator.hpp"

namespace ft
{
	template<class T>
	vector_reverse_iterator<T>::vector_reverse_iterator(void):
		_pointer(NULL)
	{}

	template<class T>
	vector_reverse_iterator<T>::~vector_reverse_iterator(void)
	{}

	template<class T>
	vector_reverse_iterator<T>::vector_reverse_iterator(T* pointer):
		_pointer(pointer)
	{}

	template<class T>
	vector_reverse_iterator<T>::vector_reverse_iterator(const vector_reverse_iterator& from):
		_pointer(from._pointer)
	{}

	template<class T>
	vector_reverse_iterator<T>&	vector_reverse_iterator<T>::operator=(const vector_reverse_iterator& from)
	{
		if (this == &from)
			return (*this);
		this->_pointer = from._pointer;
		return (*this);
	}

	template<class T>
	vector_reverse_iterator<T>&	vector_reverse_iterator<T>::operator++(void)
	{
		this->_pointer--;
		return (*this);
	}

	template<class T>
	vector_reverse_iterator<T>	vector_reverse_iterator<T>::operator++(int)
	{
		vector_reverse_iterator old(*this);
		this->_pointer--;
		return (old);
	}

	template<class T>
	vector_reverse_iterator<T>&	vector_reverse_iterator<T>::operator--(void)
	{
		this->_pointer++;
		return (*this);
	}

	template<class T>
	vector_reverse_iterator<T>	vector_reverse_iterator<T>::operator--(int)
	{
		vector_reverse_iterator old(*this);
		this->_pointer++;
		return (old);
	}

	template<class T>
	bool	vector_reverse_iterator<T>::operator==(const vector_reverse_iterator& other) const
	{
		return (this->_pointer == other._pointer);
	}

	template<class T>
	bool	vector_reverse_iterator<T>::operator!=(const vector_reverse_iterator& other) const
	{
		return (this->_pointer != other._pointer);
	}

	template<class T>
	T&	vector_reverse_iterator<T>::operator*(void) const
	{
		return (*this->_pointer);
	}

	template<class T>
	T*	vector_reverse_iterator<T>::operator->(void) const
	{
		return (this->_pointer);
	}
}