#pragma once

#include "utils/iterators.hpp"

#include "node.hpp"
#include "pair.hpp"

namespace ft
{
	template <class K, class V, class C = std::less<K> >
	class map_bidirectional_iterator: public iterator<std::bidirectional_iterator_tag, V>
	{
		public:
			typedef V	mapped_type;  
			typedef K	key_type;
			typedef C	key_compare;

			typedef ptrdiff_t	difference_type;

			typedef std::bidirectional_iterator_tag	iterator_category;

		private:
			node<K,V>*const*	_root;
			node<K,V>*			_node;
			C           		_comp;

		public:
			map_bidirectional_iterator(const C& comp = C());
			~map_bidirectional_iterator(void);

			map_bidirectional_iterator(node<K,V>*const* root, node<K,V>* current, const C& comp = C());
			map_bidirectional_iterator(const map_bidirectional_iterator& from);

			map_bidirectional_iterator&	operator=(const map_bidirectional_iterator& from);
			
			map_bidirectional_iterator&	operator++(void);
			map_bidirectional_iterator	operator++(int);

			map_bidirectional_iterator&	operator--(void);
			map_bidirectional_iterator	operator--(int);

			bool	operator==(const map_bidirectional_iterator& other) const;
			bool	operator!=(const map_bidirectional_iterator& other) const;

			pair<K,V>   operator*(void) const;
			pair<K,V>   operator->(void) const;

			node<K,V>*	current(void) const;
	};
}

#include "bidirectional_iterator.tpp"