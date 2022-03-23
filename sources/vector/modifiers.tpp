#pragma once

#include "vector.hpp"

namespace ft
{
	template <class T, class A>
	void	swap(vector<T,A>& x, vector<T,A>& y)
	{
		x.swap(y);
	}

	template <class T, class A>
	void	vector<T,A>::swap(vector& other)
	{
		A			tmp_alloc = other._alloc;
		T*			tmp_start = other._start;
		size_type	tmp_capacity = other._capacity;
		size_type	tmp_size = other._size;

		other._alloc = this->_alloc;
		other._start = this->_start;
		other._capacity = this->_capacity;
		other._size = this->_size;

		this->_alloc = tmp_alloc;
		this->_start = tmp_start;
		this->_capacity = tmp_capacity;
		this->_size = tmp_size;
	}

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
		typename I::difference_type n = std::distance(first, last);
		if (n < 0)
			throw std::out_of_range("vector::assign");
		for (size_type i = 0; i < this->_size; i++)
			this->_alloc.destroy(this->_start + i);
		if ((size_type) n > this->_capacity)
			this->reserve(n);
		for (size_type i = 0; first != last; i++, first++)
			this->_alloc.construct(this->_start + i, *first);
		this->_size = (size_type) n;
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
		typename iterator::difference_type n = std::distance(first, last);
		for (iterator it = first; it != last; it++)
			this->_alloc.destroy(&first[0]);
		for (size_type i = 0; last + i != this->end(); i++)
		{
			this->_alloc.construct(&first[i], last[i]);
			this->_alloc.destroy(&last[i]);
		}
		this->_size -= n;
		return (first);
	}

	template<class T, class A>
	typename vector<T,A>::iterator vector<T,A>::insert(iterator position, const value_type &val)
	{
		if (this->_size == this->_capacity)
		{
			typename iterator::difference_type d = std::distance(this->begin(), position);
			this->reserve((this->_capacity + 1) * 2);
			position = this->begin() + d;
		}
		for (iterator it = this->end() - 1; it != position - 1; it--)
		{
			this->_alloc.construct(&it[1], it[0]);
			this->_alloc.destroy(&it[0]);
		}
		this->_alloc.construct(&position[0], val);
		this->_size++;
		return (position);
	}

	template<class T, class A>
	void vector<T,A>::insert(iterator position, size_type n, const value_type &val)
	{
		if (this->_size + n >= this->_capacity)
		{
			typename iterator::difference_type d = std::distance(this->begin(), position);
			this->reserve((this->_capacity + n) * 2);
			position = this->begin() + d;
		}
		for (iterator it = this->end() - 1; it != position - 1; it--)
		{
			this->_alloc.construct(&it[n], it[0]);
			this->_alloc.destroy(&it[0]);
		}
		for (size_type i = 0; i < n; i++)
			this->_alloc.construct(&position[i], val);
		this->_size += n;
	}

	template <class T, class A>
	template <class I>
	void vector<T,A>::insert(iterator position, I first, I last, typename ft::enable_if<!ft::is_integral<I>::value>::type*)
	{
		typename iterator::difference_type n = std::distance(first, last);
		if (n < 0)
			throw std::out_of_range("vector::insert");
		if (this->_size + n >= this->_capacity)
		{
			typename iterator::difference_type d = std::distance(this->begin(), position);
			this->reserve((this->_capacity + n) * 2);
			position = this->begin() + d;
		}
		for (iterator it = this->end() - 1; it != position - 1; it--)
		{
			this->_alloc.construct(&it[n], it[0]);
			this->_alloc.destroy(&it[0]);
		}
		for (size_type i = 0; first != last; i++, first++)
			this->_alloc.construct(&position[i], *first);
		this->_size += n;
	}
}