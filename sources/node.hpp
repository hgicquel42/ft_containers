#pragma once

#include <string>

#define NBLACK false
#define NRED true

using namespace std;

namespace ft
{
	template <class K, class V>
	class node
	{
		public:
			K		key;
			V		value;
			node*	parent;
			node*	left;
			node*	right;
			bool	color;

			node(void);
			virtual ~node(void);

			node(const node& from);

			node&	operator=(const node& from);

			node(const K& key, const V& value, bool color = NBLACK);

			void	recolor(void);

			void	print(void) const;
	
			node*	search(const K& key) const;

			void	insert(const K& key, const V& value);

			static node*	search(const node* root, const K& key);

			static void		print(const node* root, const string& prefix = "", int position = 0);

			static void		lrotate(node*& root);

			static void		rrotate(node*& root);

			static node*&	spot(node*& root, const K& key);

			static void		insert2(node*& root, const K& key, const V& value);

			static void		insert(node*& root, const K& key, const V& value);
	};
}

#include "tree/node.tpp"