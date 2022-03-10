#pragma once

namespace ft
{
	template <class T, class A>
	int	vector<T,A>::compare(const vector& other) const
	{
		iterator a = this->begin();
		iterator b = other.begin();
		while (a != this->end() && b != other->end())
			if (*a++ != *b++)
				return (false);
		return (true);
	}

	template <class T, class A>
	int	vector<T,A>::compare2(const vector& other) const
	{
		iterator a = this->begin();
		iterator b = other.begin();
		while (a != this->end() && b != other->end() && *a == *b)
			a++, b++;
		T xa = a == this->end() ? 0 : *a;
		T xb = b == other.end() ? 0 : *b;
		return (xa - xb);
	}
}