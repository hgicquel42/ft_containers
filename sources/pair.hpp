#pragma once

namespace ft
{
	template <class A, class B>
	class pair
	{
		public:
			typedef A	first_type;
			typedef B	second_type;

		public:
			A	first;
			B	second;

		public:
			pair();

			virtual ~pair();

			pair(const pair& from);

			pair(const A& a, const B& b);

			pair& operator=(const pair& from);
	};

	template <class A, class B>
	pair<A,B>	make_pair(A a, B b);

	template <class A, class B>
 	bool operator==(const pair<A,B>& left, const pair<A,B>& right);

	template <class A, class B>
	bool operator!=(const pair<A,B>& left, const pair<A,B>& right);
	
	template <class A, class B>
	bool operator<(const pair<A,B>& left, const pair<A,B>& right);

	template <class A, class B>
	bool operator<=(const pair<A,B>& left, const pair<A,B>& right);

	template <class A, class B>
	bool operator>(const pair<A,B>& left, const pair<A,B>& right);

	template <class A, class B>
	bool operator>=(const pair<A,B>& left, const pair<A,B>& right);
}

#include "pair/pair.tpp"