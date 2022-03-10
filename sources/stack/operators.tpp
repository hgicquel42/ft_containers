#pragma once

#include "stack.hpp"

namespace ft
{
	template<class T, class C>
	bool	operator==(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left._container == right._container);
	}

	template<class T, class C>
	bool	operator!=(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left._container != right._container);
	}

	template<class T, class C>
	bool	operator<=(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left._container <= right._container);
	}

	template<class T, class C>
	bool	operator>=(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left._container >= right._container);
	}

	template<class T, class C>
	bool	operator<(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left._container < right._container);
	}

	template<class T, class C>
	bool	operator>(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left._container > right._container);
	}
}