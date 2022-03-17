#pragma once

#include "pair.hpp"
#include "node.hpp"

#include "map/iterators/bidirectional_iterator.hpp"
#include "map/iterators/reverse_iterator.hpp"

namespace ft
{
	template <class K, class V, class C = std::less<K>, class A = std::allocator<pair<const K, V> > >
	class map
	{
		public:
			typedef K			key_type;
			typedef V			mapped_type; 
			typedef pair<K, V>	value_type;
			typedef node<K,V>	node_type;
			typedef A			allocator_type;
			typedef C			key_compare;

			typedef typename A::size_type	size_type;

			typedef typename A::reference		reference;
			typedef typename A::const_reference	const_reference;

            typedef typename A::pointer			pointer;
			typedef typename A::const_pointer	const_pointer;

			typedef ft::map_bidirectional_iterator<K,V,C>						iterator;
			typedef ft::map_bidirectional_iterator<const K, const V, const C>	const_iterator;

			typedef ft::map_reverse_iterator<K,V,C>						reverse_iterator;
			typedef ft::map_reverse_iterator<const K, const V, const C>	const_reverse_iterator;
		
			class value_compare
            {
                friend class map;

				public:
                    typedef bool result_type;

                    typedef value_type first_argument_type;

                    typedef value_type second_argument_type;

                protected:
                    C comp;
                    
					value_compare(C c):
						comp(c)
					{}

				public:
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };

		private:
			node<K,V>*	_root;
			C			_comp;
			A			_alloc;
			size_type	_size;

		public:
			map(void);
			virtual ~map(void);

			explicit map(const C& comp, const A& alloc = A());
			
			map(const map& from);

			map&	operator=(const map& from);

			template <class I>
			map(I first, I last, const C& comp = C(), const A& alloc = A());

			A	get_allocator(void) const;

			C	key_comp(void) const;

			V&	at(const K& key);

			void clear(void);

			bool empty(void) const;

			size_type size(void) const;

			size_type max_size(void) const;

			size_type count(const K& key) const;
	};
}

#include "map/map.tpp"
#include "map/capacity.tpp"
#include "map/modifiers.tpp"
#include "map/lookup.tpp"