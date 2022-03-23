#pragma once

#include "pair.hpp"
#include "node.hpp"

#include "utils/compare.hpp"

#include "map/iterators/bidirectional_iterator.hpp"
#include "map/iterators/const_bidirectional_iterator.hpp"

#include "map/iterators/reverse_iterator.hpp"
#include "map/iterators/const_reverse_iterator.hpp"

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

			typedef ft::map_bidirectional_iterator<K,V,C>		iterator;
			typedef ft::const_map_bidirectional_iterator<K,V,C>	const_iterator;

			typedef ft::map_reverse_iterator<K,V,C>			reverse_iterator;
			typedef ft::const_map_reverse_iterator<K,V,C>	const_reverse_iterator;
		
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
                        return (this->comp(x.first, y.first));
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

			void	swap(map& other);

			template <class I>
			map(I first, I last, const C& comp = C(), const A& alloc = A());

			A	get_allocator(void) const;

			C				key_comp(void) const;
			value_compare	value_comp(void) const;	

			V&	at(const K& key);

			const V& at(const K& key) const;

			V&	operator[](const K& key);

			void clear(void);

			bool empty(void) const;

			size_type size(void) const;

			size_type max_size(void) const;

			size_type count(const K& key) const;

			iterator find(const K& key);

			const_iterator find(const K& key) const;

			iterator		begin(void);
			const_iterator	begin(void) const;

			iterator		end(void);
			const_iterator	end(void) const;

            reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin(void) const;

            reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;

			pair<iterator, bool>	insert(const pair<K,V>& kv);
			
			iterator	insert(iterator hint, const pair<K,V>& kv);

			template <class I>
			void insert(I first, I last);

			void erase(iterator pos);

			size_type	erase(const K& key);

			void erase(iterator first, iterator last);

			iterator	lower_bound(const K& key);
			
			iterator	upper_bound(const K& key);

			const_iterator	lower_bound(const K& key) const;
			
			const_iterator	upper_bound(const K& key) const;

			pair<iterator,iterator> equal_range(const K& key);

			pair<const_iterator,const_iterator> equal_range(const K& key) const;

			// void	print(void) const;
	};

	template <class K, class V, class C, class A>
	void	swap(map<K,V,C,A>& x, map<K,V,C,A>& y);

	template <class K, class V, class C, class A>
	bool	operator==(const map<K,V,C,A>& left, const map<K,V,C,A>& right);

	template <class K, class V, class C, class A>
	bool	operator!=(const map<K,V,C,A>& left, const map<K,V,C,A>& right);

	template <class K, class V, class C, class A>
	bool	operator<=(const map<K,V,C,A>& left, const map<K,V,C,A>& right);

	template <class K, class V, class C, class A>
	bool	operator>=(const map<K,V,C,A>& left, const map<K,V,C,A>& right);

	template <class K, class V, class C, class A>
	bool	operator<(const map<K,V,C,A>& left, const map<K,V,C,A>& right);

	template <class K, class V, class C, class A>
	bool	operator>(const map<K,V,C,A>& left, const map<K,V,C,A>& right);
}

#include "map/map.tpp"
#include "map/capacity.tpp"
#include "map/modifiers.tpp"
#include "map/lookup.tpp"
#include "map/iterators.tpp"
#include "map/operators.tpp"