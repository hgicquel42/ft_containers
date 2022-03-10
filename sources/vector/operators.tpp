#pragma once

namespace ft
{
	template <class T, class A>
	bool	vector<T,A>::compare(const vector& other) const
	{
		if (this->_size != other._size)
			return (false);
		const_iterator a = this->begin();
		const_iterator b = other.begin();
		while (a != this->end() && *a == *b)
			a++, b++;
		return (a == this->end());
	}

	template <class T, class A>
	int	vector<T,A>::compare2(const vector& other) const
	{
		if (this->_size != other._size)
			return (this->_size - other._size);
		const_iterator a = this->begin();
		const_iterator b = other.begin();
		while (a != this->end() && *a == *b)
			a++, b++;
		if (a == this->end())
			return (0);
		return (*a - *b);
	}

	template <class T, class A>
	bool	vector<T,A>::operator==(const vector& other) const
	{
		return (this->compare(other));
	}

	template <class T, class A>
	bool	vector<T,A>::operator!=(const vector& other) const
	{
		return (!this->compare(other));
	}

	template <class T, class A>
	bool	vector<T,A>::operator>=(const vector& other) const
	{
		return (this->compare2(other) >= 0);
	}

	template <class T, class A>
	bool	vector<T,A>::operator<=(const vector& other) const
	{
		return (this->compare2(other) <= 0);
	}

	template <class T, class A>
	bool	vector<T,A>::operator>(const vector& other) const
	{
		return (this->compare2(other) > 0);
	}

	template <class T, class A>
	bool	vector<T,A>::operator<(const vector& other) const
	{
		return (this->compare2(other) < 0);
	}
}