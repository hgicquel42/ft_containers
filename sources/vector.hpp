#pragma once

#include <memory>
#include <algorithm>
#include <cstddef>

#include "utils/utils.hpp"
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

			template<class I>
			vector(I first, I last, const A& alloc = A()); // TODO insert()

			vector(const vector& from); // TODO assign()

			vector&	operator=(const vector& from); // TODO assign()

			A	get_allocator(void) const;

			void	reserve(size_type size);

			void	resize(size_type size, T value);

			size_type	size(void) const;
			size_type	max_size(void) const;
			size_type	capacity(void) const;

			bool	empty(void) const;

			iterator		begin(void);
			const_iterator	begin(void) const;

			iterator		end(void);
			const_iterator	end(void) const;

			reference		front(void);
			const_reference	front(void) const;

			reference		back(void);
			const_reference	back(void) const;

			reference		at(size_type n);
			const_reference	at(size_type n) const;

			reference		operator[](size_type n);
			const_reference	operator[](size_type n) const;

			void	push_back(const T& val);
			void	pop_back(void);

			void	clear(void);
			
			void	assign(size_type count, const T& val);

			template <class I>
			void	assign(I first, I last, typename ft::enable_if<!ft::is_integral<I>::value>::type* = NULL);

			iterator	erase(iterator position);
			iterator	erase(iterator first, iterator last);

			iterator	insert(iterator position, const T& val);	
    		void		insert(iterator position, size_type n, const T& val);

			template <class I>
    		void insert (iterator position, I first, I last);
	};
}

#include "vector/constructors.tpp"
#include "vector/capacity.tpp"
#include "vector/iterators.tpp"
#include "vector/accessors.tpp"
#include "vector/modifiers.tpp"