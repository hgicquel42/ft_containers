#pragma once

#include "random_access_iterator.hpp"

namespace ft
{
	template<class T>
	vector_random_access_iterator<T>::vector_random_access_iterator(void):
		_pointer(NULL)
	{}

	template<class T>
	vector_random_access_iterator<T>::~vector_random_access_iterator(void)
	{}

	template<class T>
	vector_random_access_iterator<T>::vector_random_access_iterator(T* pointer):
		_pointer(pointer)
	{}

	template<class T>
	vector_random_access_iterator<T>::vector_random_access_iterator(const vector_random_access_iterator& from):
		_pointer(from._pointer)
	{}

	template<class T>
	vector_random_access_iterator<T>&	vector_random_access_iterator<T>::operator=(const vector_random_access_iterator& from)
	{
		if (this == &from)
			return (*this);
		this->_pointer = from._pointer;
		return (*this);
	}

	template<class T>
	vector_random_access_iterator<T>&	vector_random_access_iterator<T>::operator++(void)
	{
		this->_pointer++;
		return (*this);
	}

	template<class T>
	vector_random_access_iterator<T>	vector_random_access_iterator<T>::operator++(int)
	{
		vector_random_access_iterator old(*this);
		this->_pointer++;
		return (old);
	}

	template<class T>
	vector_random_access_iterator<T>&	vector_random_access_iterator<T>::operator--(void)
	{
		this->_pointer--;
		return (*this);
	}

	template<class T>
	vector_random_access_iterator<T>	vector_random_access_iterator<T>::operator--(int)
	{
		vector_random_access_iterator old(*this);
		this->_pointer--;
		return (old);
	}

	template<class T>
	bool	vector_random_access_iterator<T>::operator==(const vector_random_access_iterator& other) const
	{
		return (this->_pointer == other._pointer);
	}

	template<class T>
	bool	vector_random_access_iterator<T>::operator!=(const vector_random_access_iterator& other) const
	{
		return (this->_pointer != other._pointer);
	}

	template<class T>
	T&	vector_random_access_iterator<T>::operator*(void) const
	{
		return (*this->_pointer);
	}

	template<class T>
	T*	vector_random_access_iterator<T>::operator->(void) const
	{
		return (this->_pointer);
	}

	template<class T>
	vector_random_access_iterator<T>	vector_random_access_iterator<T>::operator+(ptrdiff_t n) const
	{
		return vector_random_access_iterator(this->_pointer + n);
	}

	template<class T>
	vector_random_access_iterator<T>	vector_random_access_iterator<T>::operator-(ptrdiff_t n) const
	{
		return vector_random_access_iterator(this->_pointer - n);
	}

	template<class T>
	typename vector_random_access_iterator<T>::difference_type	vector_random_access_iterator<T>::operator-(const vector_random_access_iterator& other) const
	{
		return (this->_pointer - other._pointer);
	}

	template<class T>
	bool	vector_random_access_iterator<T>::operator<(const vector_random_access_iterator& other) const
	{
		return (this->_pointer < other._pointer);
	}

	template<class T>
	bool	vector_random_access_iterator<T>::operator>(const vector_random_access_iterator& other) const
	{
		return (this->_pointer > other._pointer);
	}
	
	template<class T>
	bool	vector_random_access_iterator<T>::operator<=(const vector_random_access_iterator& other) const
	{
		return (this->_pointer <= other._pointer);
	}

	template<class T>
	bool	vector_random_access_iterator<T>::operator>=(const vector_random_access_iterator& other) const
	{
		return (this->_pointer >= other._pointer);
	}

	template<class T>
	vector_random_access_iterator<T>&	vector_random_access_iterator<T>::operator+=(difference_type n)
	{
		this->_pointer += n;
		return (*this);
	}

	template<class T>
	vector_random_access_iterator<T>&	vector_random_access_iterator<T>::operator-=(difference_type n)
	{
		this->_pointer -= n;
		return (*this);
	}

	template<class T>
	T&	vector_random_access_iterator<T>::operator[](ptrdiff_t n) const
	{
		return (*(this->_pointer + n));
	}

	template<class T>
	vector_random_access_iterator<T>	operator+(ptrdiff_t n, const vector_random_access_iterator<T>& it)
	{
		return (it + n);
	}
}