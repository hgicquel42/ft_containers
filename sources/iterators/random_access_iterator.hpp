#pragma once

#include <iterator> 

namespace ft
{
	template<class T>
	class random_access_iterator: public std::iterator<std::random_access_iterator_tag, T>
	{
		private:
			T*	pointer;
		public:
			random_access_iterator(void);
			~random_access_iterator(void);
			random_access_iterator(const T* pointer);
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
	};
}

#include "random_access_iterator.tpp"