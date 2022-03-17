#pragma once

#include "utils/iterators.hpp"
#include "node.hpp"


namespace ft
{
	template <class K, class V, class C = std::less<K> >
	class bidirectional_iterator: public iterator<std::bidirectional_iterator_tag, V>
	{
		public:
			typedef V	mapped_type;  
			typedef K	key_type;
			typedef C	key_compare;

			typedef ptrdiff_t	difference_type;

			typedef std::bidirectional_iterator_tag	iterator_category;

		private:
			node<K,V>** _slot;
			C           _comp;

		public:
			bidirectional_iterator(const C& comp = C());
			~bidirectional_iterator(void);

			bidirectional_iterator(node<K,V>** slot, const C& comp = C());
			bidirectional_iterator(const bidirectional_iterator& from);

			bidirectional_iterator&	operator=(const bidirectional_iterator& from);
			
			bidirectional_iterator&	operator++(void);
			bidirectional_iterator	operator++(int);

			bidirectional_iterator&	operator--(void);
			bidirectional_iterator	operator--(int);

			bool	operator==(const bidirectional_iterator& other) const;
			bool	operator!=(const bidirectional_iterator& other) const;

			pair<K,V>   operator*(void) const;
			pair<K,V>   operator->(void) const;
	};
}

#include "bidirectional_iterator.tpp"
#include "pair.hpp"