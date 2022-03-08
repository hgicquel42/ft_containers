#pragma once

#include "vector.hpp"

namespace ft 
{
	template<class T, class A>
	vector<T,A>::vector(void):
		_alloc(A()),
		_start(NULL),
		_capacity(0),
		_size(0)
	{}

	template<class T, class A>
	vector<T,A>::vector(const A& alloc):
		_alloc(alloc),
		_start(NULL),
		_capacity(0),
		_size(0)
	{}

	template<class T, class A>
	vector<T,A>::~vector(void)
	{
		this->_alloc.deallocate(this->_start, this->_capacity);
	}

	template<class T, class A>
	vector<T,A>::vector(size_type count, const T& value, const A& alloc):
		_alloc(alloc),
		_start(NULL),
		_capacity(0),
		_size(0)
	{
		this->_start = this->_alloc.allocate(count);
		this->_capacity = count;
		for (size_type i = 0; i < count; i++)
			this->_alloc.construct(this->_start + i, value);
		this->_size = count;
	}
}
