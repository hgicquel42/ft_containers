#pragma once

namespace ft
{
	template <class I1, class I2>
	bool equal(I1 first1, I1 last1, I2 first2)
	{
		for (; first1 != last1; first1++, first2++)
			if (*first1 != *first2)
				return (false);
		return (true);
	}

	template <class I1, class I2, class P>
	bool	equal(I1 first1, I1 last1, I2 first2, P equal)
	{
		for (; first1 != last1; first1++, first2++)
			if (!equal(*first1, *first2))
				return (false);
		return (true);
	}

	template <class I1, class I2>
	int	compare(I1 first1, I1 last1, I2 first2)
	{
		for (; first1 != last1; first1++, first2++)
			if (int comparison = *first1 - *first2)
				return (comparison);
		return (0);
	}

	template <class I1, class I2, class P>
	int	compare(I1 first1, I1 last1, I2 first2, P minus)
	{
		for (; first1 != last1; first1++, first2++)
			if (int comparison = minus(*first1, *first2))
				return (comparison);
		return (0);
	}

	template <class I1, class I2>
	bool	lexicographical_compare(I1 first1, I1 last1, I2 first2, I2 last2)
	{
		typename I1::difference_type d1 = std::distance(first1, last1);
		typename I1::difference_type d2 = std::distance(first2, last2);
		if (d1 != d2)
			return (d1 < d2);
		return (compare(first1, last1, first2) < 0);
	}

	template <class I1, class I2, class P>
	bool	lexicographical_compare(I1 first1, I1 last1, I2 first2, I2 last2, P minus)
	{
		typename I1::difference_type d1 = std::distance(first1, last1);
		typename I1::difference_type d2 = std::distance(first2, last2);
		if (d1 != d2)
			return (d1 < d2);
		return (compare(first1, last1, first2, minus) < 0);
	}
}