#pragma once

#include "vector.hpp"

namespace ft
{
	template <class T, class C = vector<T>>
	class stack
	{
		public:
			typedef T	value_type;
			typedef C	container_type;

			typedef typename C::size_type	size_type;

		private:
			C	_container;
		
		public:
			explicit stack(const C& container = C());

			bool empty() const;

			size_type size() const;

			T&			top();
			const T&	top() const;

			void push (const T& val);

			void pop();
	};
}

#include "stack/stack.tpp"