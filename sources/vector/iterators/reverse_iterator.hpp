#pragma once

#include "utils/iterators.hpp"

namespace ft
{
	template<class T>
	class vector_reverse_iterator: public iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			typedef T	value_type;
			typedef T*	pointer;
			typedef T&	reference;

			typedef ptrdiff_t	difference_type;

			typedef std::bidirectional_iterator_tag	iterator_category;
		private:
			T*	_pointer;
		public:
			vector_reverse_iterator(void);
			~vector_reverse_iterator(void);
			vector_reverse_iterator(T* pointer);
			vector_reverse_iterator(const vector_reverse_iterator& from);

			vector_reverse_iterator&	operator=(const vector_reverse_iterator& from);
			
			vector_reverse_iterator&	operator++(void);
			vector_reverse_iterator	operator++(int);

			vector_reverse_iterator&	operator--(void);
			vector_reverse_iterator	operator--(int);

			bool	operator==(const vector_reverse_iterator& other) const;
			bool	operator!=(const vector_reverse_iterator& other) const;

			T&	operator*(void) const;
			T*	operator->(void) const;
	};
}

#include "reverse_iterator.tpp"