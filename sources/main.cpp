#include "vector.hpp"
#include "stack.hpp"
#include "node.hpp"

#include <vector>
#include <iostream>

using namespace std;

template <class T>
void	print(ft::vector<T>& vector)
{
	cout << "-----------" << "\n";
	cout << vector.size() << "\n";
	cout << vector.capacity() << "\n";
	cout << vector.max_size() << "\n";
	cout << "-----------" << "\n";
}

typedef ft::node<int,string>	node;

int	main(void)
{
	node*	root;
	
	root = new node(42, "the root");
	node::insert(root, 43, "lol");
	node::insert(root, 46, "hello");
	node::insert(root, 47, "world");
	node::insert(root, 1, "lol");
	// root->left = new node(43, "lol", NRED);
	// root->right = new node(41, "lol");
	// root->left->left = new node(36, "hello", NRED);
	// root->left->right = new node(421, "world");
	// root->right->right = new node(1, "it");
	// root->right->right->right = new node(123, "works");

	node::print(root);
	node::rrotate(root);
	node::print(root);
	node::lrotate(root);
	node::print(root);

	// ft::vector<int>				vec;
	// ft::vector<int>				vec2;
	// ft::vector<int>::iterator	it;
	// ft::vector<int>::reverse_iterator	it;

	// print(vec);
	// vec.reserve(200);
	// print(vec);
	// vec.reserve(10);

	// for (int i = 0; i < 10; i++)
	// 	vec.push_back(i);
	// vec.push_back(43);
	// vec.push_back(50);

	// vec.push_back(42);
	// vec.erase(vec.begin());

	// for (int i = 0; i < 10; i++)
	// 	vec2.push_back(i);
	// vec2.push_back(43);
	// vec2.push_back(50);

	// print(vec);
	// vec.insert(vec.begin() + 5, 42);
	// print(vec);

	// vec.swap(vec2);

	// vec.pop_back();

	// for (it = vec.erase(vec.begin() + 5, vec.begin() + 10); it != vec.end(); it++)
	// 	std::cout << *it << "\n";

	// vec.erase(vec.begin() + 9)

	// for (it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << "\n";

	// for (it = vec.rbegin(); it != vec.rend(); it--)
	// 	std::cout << *it << "\n";

	// for (it = vec2.begin(); it != vec2.end(); it++)
	// 	std::cout << *it << "\n";

	// std::cout << "== " << (vec == vec2) << "\n";
	// std::cout << "!= " << (vec != vec2) << "\n";
	// std::cout << "<= " << (vec <= vec2) << "\n";
	// std::cout << ">= " << (vec >= vec2) << "\n";
	// std::cout << "< " << (vec < vec2) << "\n";
	// std::cout << "> " << (vec > vec2) << "\n";

	// ft::stack<int>	stack(vec);
	// ft::stack<int>	stack2(vec2);

	// std::cout << "== " << (stack == stack2) << "\n";
	// std::cout << "!= " << (stack != stack2) << "\n";
	// std::cout << "<= " << (stack <= stack2) << "\n";
	// std::cout << ">= " << (stack >= stack2) << "\n";
	// std::cout << "< " << (stack < stack2) << "\n";
	// std::cout << "> " << (stack > stack2) << "\n";

	return (0);
}