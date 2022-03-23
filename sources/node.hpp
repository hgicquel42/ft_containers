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

			static node*	sibling(node* current);

			static node*	uncle(node* current);

			static node**	slot(node** root, node* current);

			static bool		isblack(node* slot);

			static bool		isred(node* slot);

			static node*	minimum(node* current);

			static node*	maximum(node* current);

			static node*	next(node* current);

			static node*	previous(node*const* root, node* current);

			static const node*	maximum(const node* current);

			static const node*	next(const node* current);

			static const node*	previous(const node*const* root, const node* current);

			template <class C>
			static node*	search(node* current, const K& key);

			static void		print(const node* root, const string& prefix = "", int position = 0);

			static void		lrotate(node** root, node* current);

			static void		rrotate(node** root, node* current);

			template <class C>
			static node**	spot(node** parent, node** root, const K& key);

			template <class C>
			static pair<node*, bool>	insert(node** root, const K& key, const V& value);

			template <class C>
			static bool		erase(node** root, const K& key);

			static bool		erase(node** root, node* current);

			static node*	random(node* current);

		private:
		
			static void		insertf(node** root, node* slot);

			static void		erasef(node** root, node* slot);
	};
}

#include "node/node.tpp"
#include "node/print.tpp"
#include "node/peers.tpp"
#include "node/rotate.tpp"
#include "node/insert.tpp"
#include "node/erase.tpp"