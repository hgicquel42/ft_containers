#pragma once

#include "random_access_iterator.hpp"

namespace ft
{
	template<class T>
	random_access_iterator<T>::random_access_iterator(void):
		pointer(NULL)
	{}

	template<class T>
	random_access_iterator<T>::~random_access_iterator(void)
	{}

	template<class T>
	random_access_iterator<T>::random_access_iterator(const T* pointer):
		pointer(pointer)
	{}

	template<class T>
	random_access_iterator<T>::random_access_iterator(const random_access_iterator& from):
		pointer(from.pointer)
	{}

	template<class T>
	random_access_iterator<T>&	random_access_iterator<T>::operator=(const random_access_iterator& from)
	{
		if (this == &from)
			return ;
		this->pointer = from.pointer;
		return (*this);
	}

	template<class T>
	random_access_iterator<T>&	random_access_iterator<T>::operator++(void)
	{
		this->pointer++;
		return (*this);
	}

	template<class T>
	random_access_iterator<T>	random_access_iterator<T>::operator++(int)
	{
		random_access_iterator old(*this);
		this->pointer++;
		return (old);
	}

	template<class T>
	random_access_iterator<T>&	random_access_iterator<T>::operator--(void)
	{
		this->pointer--;
		return (*this);
	}

	template<class T>
	random_access_iterator<T>	random_access_iterator<T>::operator--(int)
	{
		random_access_iterator old(*this);
		this->pointer--;
		return (old);
	}

	template<class T>
	bool	random_access_iterator<T>::operator==(const random_access_iterator& other) const
	{
		return (this->pointer == other.pointer);
	}

	template<class T>
	bool	random_access_iterator<T>::operator!=(const random_access_iterator& other) const
	{
		return (this->pointer != other.pointer);
	}

	template<class T>
	T&	random_access_iterator<T>::operator*(void) const
	{
		return (*this->pointer);
	}

	template<class T>
	T*	random_access_iterator<T>::operator->(void) const
	{
		return (this->pointer);
	}
}