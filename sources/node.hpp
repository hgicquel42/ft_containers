#pragma once

#include <string>

#include "pair.hpp"

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

			node(node* parent, const K& key, const V& value, bool color = NBLACK);

			void	recolor(void);

			static node**	sibling(node* current);

			static node**	uncle(node* current);

			static node**	slot(node** root, node* current);

			static bool		isblack(node* slot);

			static bool		isred(node* slot);

			static node**	minimum(node** slot);

			static node**	maximum(node** slot);

			static node**	next(node** slot);

			static node**	previous(node** slot);

			static node*	search(node* root, const K& key);

			static void		print(const node* root, const string& prefix = "", int position = 0);

			static void		lrotate(node** slot);

			static void		rrotate(node** slot);

			static node**	spot(node** parent, node** root, const K& key);

			static pair<node**, bool>	insert(node** root, const K& key, const V& value);

			static bool		erase(node** root, const K& key);

			static void		erase(node** root, node** slot);

			static node**	random(node** root);

		private:
		
			static void		insertf(node** root, node** slot);

			static void		erasef(node** root, node** slot);
	};
}

#include "node/node.tpp"
#include "node/print.tpp"
#include "node/peers.tpp"
#include "node/rotate.tpp"
#include "node/insert.tpp"
#include "node/erase.tpp"