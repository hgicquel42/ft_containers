#pragma once

#define BLACK false
#define RED true

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

			node(const K& key, const V& value, node* left = NULL, node* right = NULL, bool color = BLACK);
	
			node*	search(const K& key);
	};
}