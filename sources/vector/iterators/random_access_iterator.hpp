#pragma once

#include "utils/iterators.hpp"

namespace ft
{
	template<class T>
	class vector_random_access_iterator: public iterator<std::random_access_iterator_tag, T>
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
			vector_random_access_iterator(void);
			~vector_random_access_iterator(void);
			vector_random_access_iterator(T* pointer);
			vector_random_access_iterator(const vector_random_access_iterator& from);

			vector_random_access_iterator&	operator=(const vector_random_access_iterator& from);
			
			vector_random_access_iterator&	operator++(void);
			vector_random_access_iterator	operator++(int);

			vector_random_access_iterator&	operator--(void);
			vector_random_access_iterator	operator--(int);

			bool	operator==(const vector_random_access_iterator& other) const;
			bool	operator!=(const vector_random_access_iterator& other) const;

			T&	operator*(void) const;
			T*	operator->(void) const;

			vector_random_access_iterator	operator+(difference_type n) const;
			vector_random_access_iterator	operator-(difference_type n) const;

			difference_type	operator-(const vector_random_access_iterator& other) const;

			bool	operator>(const vector_random_access_iterator& other) const;
			bool	operator<(const vector_random_access_iterator& other) const;

			bool	operator>=(const vector_random_access_iterator& other) const;
			bool	operator<=(const vector_random_access_iterator& other) const;

			vector_random_access_iterator&	operator+=(difference_type n);
			vector_random_access_iterator&	operator-=(difference_type n);

			T&	operator[](difference_type n) const;
	};

	template<class T>
	vector_random_access_iterator<T>	operator+(ptrdiff_t n, const vector_random_access_iterator<T>& it);
}

#include "random_access_iterator.tpp"