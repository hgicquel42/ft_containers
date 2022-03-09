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
	void	vector<T,A>::assign(size_type count, const T& val)
	{
		for (size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_start + i);
		for (size_type i = 0; i < count; i++)
			this->_alloc.construct(this->_start + i, val);
		this->_size = count;
	}

	template <class T, class A>
	template <class I>
	void	vector<T,A>::assign(I first, I last, typename ft::enable_if<!ft::is_integral<I>::value>::type*)
	{
		typename I::difference_type count = std::distance(first, last);
		for (size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_start + i);
		if (count < 0)
			throw std::out_of_range("vector::assign");
		if ((size_type) count > this->_capacity)
			this->reserve(count);
		for (size_type i = 0; first != last; i++, first++)
			this->_alloc.construct(this->_start + i, *first);
		this->_size = (size_type) count;
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

	template <class T, class A>
	typename vector<T,A>::iterator	vector<T,A>::erase(iterator first, iterator last)
	{
		typename iterator::difference_type count = std::distance(first, last);
		for (iterator it = first; it != last; it++)
			this->_alloc.destroy(&first[0]);
		for (size_type i = 0; last + i != this->end(); i++)
		{
			this->_alloc.construct(&first[i], last[i]);
			this->_alloc.destroy(&last[i]);
		}
		this->_size -= count;
		return (first);
	}
}