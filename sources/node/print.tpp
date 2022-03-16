#pragma once

#include <iostream>

#include "node.hpp"

#include "utils/colors.hpp"

namespace ft
{
	template <class K, class V>
	void	node<K,V>::print(const node* root, const string& prefix, int position)
	{
		cout << prefix;

		if (position == -1)
			cout << "|---";
		else if (position == 1)
			cout << "└---";

		if (!root) {
			cout << "null\n";
			return ;
		}

		if (root->color == NRED)
			cout << RED;
		cout << "[" << root->key << "]" << RESET;
		cout << " = " << root->value;
		// Uncomment to show parent address and current address
		// cout << " (" << root->parent << " -> " << root << ")";
		cout << "\n";

		string nprefix = prefix;
		if (position == -1)
			nprefix += "│   ";
		else if (position == 1)
			nprefix += "    ";
		print(root->left, nprefix, -1);
		print(root->right, nprefix, 1);
	}
}