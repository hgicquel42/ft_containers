#pragma once

#include "vector.hpp"

#include "utils/compare.hpp"

namespace ft
{
	template <class T, class C = vector<T> >
	class stack
	{
		public:
			typedef T	value_type;
			typedef C	container_type;

			typedef typename C::size_type	size_type;

		protected:
			C	c;
		
		public:
			explicit stack(const C& container = C());

			virtual ~stack();

			stack& operator=(const stack& from);

			bool empty(void) const;

			size_type size(void) const;

			T&			top(void);
			const T&	top(void) const;

			void push (const T& val);

			void pop();

			template<class T2, class C2>
			friend bool	operator==(const stack<T2,C2>& left, const stack<T2,C2>& right);

			template<class T2, class C2>
			friend bool	operator!=(const stack<T2,C2>& left, const stack<T2,C2>& right);

			template<class T2, class C2>
			friend bool	operator<=(const stack<T2,C2>& left, const stack<T2,C2>& right);

			template<class T2, class C2>
			friend bool	operator>=(const stack<T2,C2>& left, const stack<T2,C2>& right);

			template<class T2, class C2>
			friend bool	operator<(const stack<T2,C2>& left, const stack<T2,C2>& right);

			template<class T2, class C2>
			friend bool	operator>(const stack<T2,C2>& left, const stack<T2,C2>& right);
	};
}

#include "stack/stack.tpp"
#include "stack/operators.tpp"