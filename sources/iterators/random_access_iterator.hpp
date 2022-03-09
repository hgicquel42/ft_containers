#pragma once

#include "iterators.hpp"

namespace ft
{
	template<class T>
	class random_access_iterator: public iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef T	value_type;
			typedef T*	pointer;
			typedef T&	reference;

			typedef ptrdiff_t	difference_type;

			typedef std::random_access_iterator_tag	iterator_category;
		private:
			T*	_pointer;
		public:
			random_access_iterator(void);
			~random_access_iterator(void);
			random_access_iterator(T* pointer);
			random_access_iterator(const random_access_iterator& from);

			random_access_iterator&	operator=(const random_access_iterator& from);
			
			random_access_iterator&	operator++(void);
			random_access_iterator	operator++(int);

			random_access_iterator&	operator--(void);
			random_access_iterator	operator--(int);

			bool	operator==(const random_access_iterator& other) const;
			bool	operator!=(const random_access_iterator& other) const;

			T&	operator*(void) const;
			T*	operator->(void) const;

			random_access_iterator	operator+(difference_type n) const;
			random_access_iterator	operator-(difference_type n) const;

			difference_type	operator-(const random_access_iterator& other) const;

			T&	operator[](difference_type n) const;
	};
}

#include "random_access_iterator.tpp"