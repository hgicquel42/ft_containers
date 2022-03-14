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
	};
}

#include "tree/node.tpp"