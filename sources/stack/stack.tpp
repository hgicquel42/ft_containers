#pragma once

#include "stack.hpp"

namespace ft
{
	template <class T, class C>
	stack<T,C>::stack(const C& container):
		_container(container)
	{}

	
}