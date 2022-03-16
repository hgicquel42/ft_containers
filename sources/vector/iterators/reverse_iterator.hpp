#pragma once

#include "utils/iterators.hpp"

namespace ft
{
	template<class T>
	class reverse_iterator: public iterator<std::bidirectional_iterator_tag, T>
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
			reverse_iterator(void);
			~reverse_iterator(void);
			reverse_iterator(T* pointer);
			reverse_iterator(const reverse_iterator& from);

			reverse_iterator&	operator=(const reverse_iterator& from);
			
			reverse_iterator&	operator++(void);
			reverse_iterator	operator++(int);

			reverse_iterator&	operator--(void);
			reverse_iterator	operator--(int);

			bool	operator==(const reverse_iterator& other) const;
			bool	operator!=(const reverse_iterator& other) const;

			T&	operator*(void) const;
			T*	operator->(void) const;
	};
}

#include "reverse_iterator.tpp"