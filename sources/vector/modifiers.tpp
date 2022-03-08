#pragma once

#include <iostream>

namespace ft
{
	template <class T, class A>
	void	vector<T,A>::push_back(const T& value)
	{
		if (this->_size == this->_capacity)
			this->reserve((this->_capacity + 1) * 2);
		this->_alloc.construct(this->_start + this->_size++, value);
	}

	template <class T, class A>
	void	vector<T,A>::pop_back(void)
	{
		this->_alloc.destroy(this->_start + this->_size-- - 1);
	}

	template <class T, class A>
	void	vector<T,A>::clear(void)
	{
		for (size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_start + i);
		this->_size = 0;
	}

	template <class T, class A>
	typename vector<T,A>::iterator	vector<T,A>::erase(iterator position)
	{
		this->_alloc.destroy(&position[0]);
		for (iterator it = position; it + 1 != this->end(); it++)
		{
			this->_alloc.construct(&it[0], it[1]);
			this->_alloc.destroy(&it[1]);
		}
		this->_size--;
		return (position);
	}
}