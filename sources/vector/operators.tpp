#pragma once

namespace ft
{
	template <class T, class A>
	static bool	compare(const vector<T,A>& left, const vector<T,A>& right)
	{
		if (left.size() != right.size())
			return (false);
		typename vector<T,A>::const_iterator a = left.begin();
		typename vector<T,A>::const_iterator b = right.begin();
		while (a != left.end() && *a == *b)
			a++, b++;
		return (a == left.end());
	}

	template <class T, class A>
	static int	compare2(const vector<T,A>& left, const vector<T,A>& right)
	{
		if (left.size() != right.size())
			return (left.size() - right.size());
		typename vector<T,A>::const_iterator a = left.begin();
		typename vector<T,A>::const_iterator b = right.begin();
		while (a != left.end() && *a == *b)
			a++, b++;
		if (a == left.end())
			return (0);
		return (*a - *b);
	}

	template <class T, class A>
	bool	operator==(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (compare(left, right));
	}

	template <class T, class A>
	bool	operator!=(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (!compare(left, right));
	}

	template <class T, class A>
	bool	operator>=(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (compare2(left, right) >= 0);
	}

	template <class T, class A>
	bool	operator<=(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (compare2(left, right) <= 0);
	}

	template <class T, class A>
	bool	operator>(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (compare2(left, right) > 0);
	}

	template <class T, class A>
	bool	operator<(const vector<T,A>& left, const vector<T,A>& right)
	{
		return (compare2(left, right) < 0);
	}
}