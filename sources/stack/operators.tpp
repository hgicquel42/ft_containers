#pragma once

#include "stack.hpp"

namespace ft
{
	template<class T, class C>
	bool	operator==(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left.c == right.c);
	}

	template<class T, class C>
	bool	operator!=(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left.c != right.c);
	}

	template<class T, class C>
	bool	operator<=(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left.c <= right.c);
	}

	template<class T, class C>
	bool	operator>=(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left.c >= right.c);
	}

	template<class T, class C>
	bool	operator<(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left.c < right.c);
	}

	template<class T, class C>
	bool	operator>(const stack<T,C>& left, const stack<T,C>& right)
	{
		return (left.c > right.c);
	}
}