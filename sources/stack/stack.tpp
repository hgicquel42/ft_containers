#pragma once

#include "stack.hpp"
namespace ft
{
	template <class T, class C>
	stack<T,C>::stack(const C& container):
		_container(container)
	{}

	template <class T, class C>
	bool	stack<T,C>::empty(void) const
	{
		return (this->_container.empty());
	}

	template <class T, class C>
	typename stack<T,C>::size_type	stack<T,C>::size(void) const
	{
		return (this->_container.size());
	}

	template <class T, class C>
	T&	stack<T,C>::top(void)
	{
		return (this->_container.back());
	}

	template <class T, class C>
	const T&	stack<T,C>::top(void) const
	{
		return (this->_container.back());
	}

	template <class T, class C>
	void	stack<T,C>::push(const T& val)
	{
		this->_container.push_back(val);
	}

	template <class T, class C>
	void	stack<T,C>::pop(void)
	{
		this->_container.pop_back();
	}
}