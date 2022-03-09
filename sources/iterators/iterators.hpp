#pragma once

#include <cstddef>

namespace ft
{
    template <class I> struct iterator_traits
    {
        typedef typename I::value_type			value_type;
        typedef typename I::pointer				pointer;
        typedef typename I::reference			reference;
		typedef typename I::difference_type		difference_type;
        typedef typename I::iterator_category	iterator_category;
    };
    
    template <class T> struct iterator_traits<T*>
    {
        typedef T	value_type;
        typedef T*	pointer;
        typedef T&	reference;

		typedef ptrdiff_t	difference_type;

        typedef std::random_access_iterator_tag  iterator_category;
    };
    
    template <class T> class iterator_traits<const T*>
    {
        typedef T	value_type;
        typedef T*	pointer;
        typedef T&	reference;

		typedef ptrdiff_t	difference_type;

        typedef std::random_access_iterator_tag  iterator_category;
    };

	template <class C, class T, class D = ptrdiff_t, class P = T*, class R = T&>
	class iterator
	{
		public:
			typedef T	value_type;
			typedef P	pointer;
			typedef R	reference;
			typedef D	difference_type;
			typedef C	iterator_category;
	};
}