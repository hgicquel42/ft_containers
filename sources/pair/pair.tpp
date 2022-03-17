#pragma once

#include "pair.hpp"

namespace ft
{
	template <class A, class B>
	pair<A,B>::pair(void)
	{}

	template <class A, class B>
	pair<A,B>::~pair(void)
	{}

	template <class A, class B>
	pair<A,B>::pair(const pair& from):
		first(from.first),
		second(from.second)
	{}

	template <class A, class B>
	pair<A,B>::pair(const A& first, const B& second):
		first(first),
		second(second)
	{}

	template <class A, class B>
	pair<A,B>&	pair<A,B>::operator=(const pair& from)
	{
		if (this == &from)
			return (*this);
		this->first = from.first;
		this->second = from.second;
		return (*this);
	}

	template <class A, class B>
	pair<A,B>	make_pair(A a, B b)
	{
		return (pair<A,B>(a, b));
	}

	template <class A, class B>
 	bool operator==(const pair<A,B>& left, const pair<A,B>& right)
	{
		return (left.first == right.first && left.second == right.second);
	}

	template <class A, class B>
	bool operator!=(const pair<A,B>& left, const pair<A,B>& right)
	{
		return (left.first != right.first || left.second != right.second);
	}

	template <class A, class B>
	bool operator<(const pair<A,B>& left, const pair<A,B>& right)
	{
		if (left.first != right.first)
			return (left.first < right.first);
		return (left.second < right.second);
	}

	template <class A, class B>
	bool operator<=(const pair<A,B>& left, const pair<A,B>& right)
	{
		if (left.first != right.first)
			return (left.first < right.first);
		if (left.second != right.second)
			return (left.second < right.second);
		return (true);
	}

	template <class A, class B>
	bool operator>(const pair<A,B>& left, const pair<A,B>& right)
	{
		if (left.first != right.first)
			return (left.first > right.first);
		return (left.second > right.second);
	}

	template <class A, class B>
	bool operator>=(const pair<A,B>& left, const pair<A,B>& right)
	{
		if (left.first != right.first)
			return (left.first > right.first);
		if (left.second != right.second)
			return (left.second > right.second);
		return (true);
	}
}