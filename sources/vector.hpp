#pragma once

#include <memory>
#include <algorithm>
#include <cstddef>

#include "iterators/random_access_iterator.hpp"

namespace ft
{
	template<class T, class A = std::allocator<T> >
	class vector
	{
		public:
			typedef T	value_type;
			typedef A	allocator_type;

			typedef typename A::size_type		size_type;

			typedef typename A::reference		reference;
			typedef typename A::const_reference	const_reference;
	
			typedef typename A::pointer			pointer;
			typedef typename A::const_pointer	const_pointer;

			typedef random_access_iterator<T>		iterator;
			typedef random_access_iterator<const T>	const_iterator;

		private:
			A			_alloc;
			T*			_start;
			size_type	_capacity;
			size_type	_size;

		public:

			vector(void);
			~vector(void);

			explicit vector(const A& alloc);

			explicit vector(size_type count, const T& value = T(), const A& alloc = A());

			explicit vector(size_type count);

			template<class I>
			vector(I first, I last, const A& alloc = A());

			vector(const vector& other);

			void	reserve(size_type size);
			void	resize(size_type size, T value);

			size_type	size(void) const;
			size_type	max_size(void) const;
			size_type	capacity(void) const;

			bool	empty(void) const;

			iterator	begin(void);
			iterator	end(void);
	};
}

#include "vector/constructors.tpp"
#include "vector/capacity.tpp"
#include "vector/iterators.tpp"