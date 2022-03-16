#pragma once

#include "vector.hpp"

#include "utils/compare.hpp"

namespace ft
{
	template <class T, class A>
	static bool	equal(const vector<T,A>& left, const vector<T,A>& right)
	{
		if (left.size() != right.size())
			return (false);
		return (ft::equal(left.begin(), left.end(), right.begin()));
	}

	template <class T, class A>
	static int	compare(const vector<T,A>& left, const vector<T,A>& right)
	{
		if (left.size() != right.size())
			return (left.size() - right.size());
		return (ft::compare(left.begin(), left.end(), right.begin()));
	}

	template <class T, class A>
	bool	operator==(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (equal(left, right));
	}

	template <class T, class A>
	bool	operator!=(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (!equal(left, right));
	}

	template <class T, class A>
	bool	operator>=(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (compare(left, right) >= 0);
	}

	template <class T, class A>
	bool	operator<=(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (compare(left, right) <= 0);
	}

	template <class T, class A>
	bool	operator>(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (compare(left, right) > 0);
	}

	template <class T, class A>
	bool	operator<(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (compare(left, right) < 0);
	}
}