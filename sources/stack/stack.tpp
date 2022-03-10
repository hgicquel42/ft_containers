#pragma once

#include "stack.hpp"
namespace ft
{
	template <class T, class C>
	stack<T,C>::stack(const C& container):
		c(container)
	{}

	template <class T, class C>
	stack<T,C>::~stack()
	{}

	template <class T, class C>
	stack<T,C>&	stack<T,C>::operator=(const stack& from)
	{
		if (this == &from)
			return (*this);
		this->c = from.c;
		return (*this);
	}

	template <class T, class C>
	bool	stack<T,C>::empty(void) const
	{
		return (this->c.empty());
	}

	template <class T, class C>
	typename stack<T,C>::size_type	stack<T,C>::size(void) const
	{
		return (this->c.size());
	}

	template <class T, class C>
	T&	stack<T,C>::top(void)
	{
		return (this->c.back());
	}

	template <class T, class C>
	const T&	stack<T,C>::top(void) const
	{
		return (this->c.back());
	}

	template <class T, class C>
	void	stack<T,C>::push(const T& val)
	{
		this->c.push_back(val);
	}

	template <class T, class C>
	void	stack<T,C>::pop(void)
	{
		this->c.pop_back();
	}
}