#pragma once

#include "map.hpp"

#include "utils/compare.hpp"

namespace ft
{
	template <class K, class V, class C, class A>
	bool operator==(const map<K,V,C,A>& left, const map<K,V,C,A>& right)
	{
		return (ft::equal(left.begin(), left.end(), right.begin()));
	}

	template <class K, class V, class C, class A>
	bool operator<(const map<K,V,C,A>& left, const map<K,V,C,A>& right)
	{
		return (ft::compare(left.begin(), left.end(), right.begin(), left.value_comp()));
	}

	template <class K, class V, class C, class A>
	bool operator!=(const map<K,V,C,A>& left, const map<K,V,C,A>& right)
	{
		return (!(left == right));
	}

	template <class K, class V, class C, class A>
	bool operator<=(const map<K,V,C,A>& left, const map<K,V,C,A>& right)
	{
		return (!(left > right));
	}

	template <class K, class V, class C, class A>
	bool operator>(const map<K,V,C,A>& left, const map<K,V,C,A>& right)
	{
		return (right < left);
	}

	template <class K, class V, class C, class A>
	bool operator>=(const map<K,V,C,A>& left, const map<K,V,C,A>& right)
	{
		return (!(left < right));
	}
}