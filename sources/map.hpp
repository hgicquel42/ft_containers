#pragma once

#include "pair.hpp"
#include "node.hpp"

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