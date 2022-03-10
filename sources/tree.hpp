#pragma once

#include <memory>
#include <functional>

#include "pair.hpp"

namespace ft
{
	template <class K, class V>
	class node
	{

	};

	template <class K, class V, class C = std::less<K>, class A = std::allocator<pair<const K, V> > >
	class tree
	{

	};
}