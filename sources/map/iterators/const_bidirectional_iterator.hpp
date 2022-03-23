#pragma once

#include "utils/iterators.hpp"

#include "node.hpp"
#include "pair.hpp"

namespace ft
{
	template <class K, class V, class C = std::less<K> >
	class const_map_bidirectional_iterator: public iterator<std::bidirectional_iterator_tag, V>
	{
		public:
			typedef V	mapped_type;  
			typedef K	key_type;
			typedef C	key_compare;

			typedef ptrdiff_t	difference_type;

			typedef std::bidirectional_iterator_tag	iterator_category;

		private:
			const node<K,V>*const*	_root;
			const node<K,V>*		_node;
			C           			_comp;

		public:
			const_map_bidirectional_iterator(const C& comp = C());
			~const_map_bidirectional_iterator(void);

			const_map_bidirectional_iterator(const node<K,V>*const* root, const node<K,V>* current, const C& comp = C());
			const_map_bidirectional_iterator(const const_map_bidirectional_iterator& from);

			const_map_bidirectional_iterator&	operator=(const const_map_bidirectional_iterator& from);
			
			const_map_bidirectional_iterator&	operator++(void);
			const_map_bidirectional_iterator	operator++(int);

			const_map_bidirectional_iterator&	operator--(void);
			const_map_bidirectional_iterator	operator--(int);

			bool	operator==(const const_map_bidirectional_iterator& other) const;
			bool	operator!=(const const_map_bidirectional_iterator& other) const;

			pair<K,V>   operator*(void) const;
			pair<K,V>   operator->(void) const;

			const node<K,V>*	current(void) const;
	};
}

#include "const_bidirectional_iterator.tpp"