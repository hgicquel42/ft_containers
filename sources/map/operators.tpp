#pragma once

#include "map.hpp"

namespace ft
{
	template <class K, class V, class C, class A>
	bool operator==(const map<K,V,C,A>& lhs, const map<K,V,C,A>& rhs)
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class K, class V, class C, class A>
	bool operator<(const map<K,V,C,A>& lhs, const map<K,V,C,A>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class K, class V, class C, class A>
	bool operator!=(const map<K,V,C,A>& lhs, const map<K,V,C,A>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class K, class V, class C, class A>
	bool operator<=(const map<K,V,C,A>& lhs, const map<K,V,C,A>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class K, class V, class C, class A>
	bool operator>(const map<K,V,C,A>& lhs, const map<K,V,C,A>& rhs)
	{
		return (rhs < lhs);
	}

	template <class K, class V, class C, class A>
	bool operator>=(const map<K,V,C,A>& lhs, const map<K,V,C,A>& rhs)
	{
		return (!(lhs < rhs));
	}
}