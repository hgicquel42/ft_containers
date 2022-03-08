#pragma once

#include "vector.hpp"

namespace ft 
{
	template<class T, class A>
	A	vector<T,A>::get_allocator(void) const
	{
		return (this->_alloc);
	}

	template<class T, class A>
	void	vector<T,A>::reserve(size_type capacity)
	{
		if (capacity <= this->_capacity)
			return ;
		T* start = this->_alloc.allocate(capacity);
		for (size_type i = 0; i < this->_size; i++)
			this->_alloc.construct(start + i, this->_start[i]);
		this->_alloc.deallocate(this->_start, this->_capacity);
		this->_start = start;
		this->_capacity = capacity;
	}

	template<class T, class A>
	void	vector<T,A>::resize(size_type count, T value)
	{
		if (count > this->_capacity)
			this->reserve(count);
		if (count == this->_size)
			return ;
		if (count > this->_size)
		{
			for (size_type i = this->_size; i < count; i++)
				this->_alloc.construct(this->_start + i, value);
			this->_size = count;
		}
		else
		{
			for (size_type i = count; i < this->_size; i++)
				this->_alloc.destroy(this->_start + i);
			this->_size = count;
		}
	}

	template<class T, class A>
	typename vector<T,A>::size_type	vector<T,A>::size(void) const
	{
		return (this->_size);
	}

	template<class T, class A>
	typename vector<T,A>::size_type	vector<T,A>::max_size(void) const
	{
		return (this->_alloc.max_size());
	}

	template<class T, class A>
	typename vector<T,A>::size_type	vector<T,A>::capacity(void) const
	{
		return (this->_capacity);
	}

	template<class T, class A>
	bool	vector<T,A>::empty(void) const
	{
		return (this->_size == 0);
	}
}
