#include "vector.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "map.hpp"

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

typedef ft::node<int,int>	node;

int	random(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

int	main(void)
{
	ft::map<int,int>	map;

	

	// node*	root = NULL;

	srand(time(NULL));
	
	// root = new node(NULL, 0, "root");
	// node::print(root);
	// node::insert(&root, 10, "10");
	// node::print(root);
	// node::insert(&root, -10, "-10");
	// node::print(root);
	// node::insert(&root, 20, "20");
	// node::print(root);
	// node::insert(&root, 5, "5");
	// node::print(root);
	// node::insert(&root, 15, "15");
	// node::print(root);
	// node::insert(&root, -5, "-5");
	// node::print(root);
	// node::insert(&root, -10, "still -10");

	// node::print(root);

	// cout << "--- erasing ---\n";

	// node::print(root);
	// node::erase(&root, 10);
	// node::print(root);
	// node::erase(&root, 5);
	// node::print(root);

	// node::erase(&root, -10);
	// node::print(root);
	// node::erase(&root, 20);
	// node::print(root);
	// node::erase(&root, 15);
	// node::print(root);
	// node::erase(&root, -5);
	// node::print(root);

	// node::erase(&root);
	// node::print(root);

	// node::insert(&root, 12, "lol");
	// node::print(root);

	// for (int i = 0; i < 100 * 1000 * 1000; i++) {
	// 	node::insert(&root, random(-200, 200), i);
	// 	// node::print(root);
	// }

	// // node::print(root);

	// for (int i = 0; i < 50 * 1000 * 1000; i++) {
	// 	node::erase(&root, node::random(&root));
	// 	// node::print(root);
	// }

	// // node::print(root);

	// for (int i = 0; i < 50 * 1000 * 1000; i++) {
	// 	node::insert(&root, random(-200, 200), i);
	// 	// node::print(root);
	// }

	// node::lrotate(&root);
	// node::print(root);
	// node::rrotate(&root);
	// node::print(root);

	// while (root) {
	// 	node::erase(&root, node::random(&root));
	// 	// node::print(root);
	// }
		
	// node::print(root);

	// root->left = new node(root, 0, "aa");
	// root->left->left = new node(root->left, 0, "aaa");
	// root->left->left->left = new node(root->left->left, 0, "aaaa");
	// root->left->left->right = new node(root->left->left, 0, "aaab");
	// root->left->right = new node(root->left, 0, "aab");
	// root->left->right->left = new node(root->left->right, 0, "aaba");
	// root->left->right->right = new node(root->left->right, 0, "aabb");

	// root->right = new node(root, 0, "ab", NRED);
	// root->right->left = new node(root->right, 0, "aba");
	// root->right->left->left = new node(root->right->left, 0, "abaa");
	// root->right->left->right = new node(root->right->left, 0, "abab");
	// root->right->right = new node(root->right, 0, "abb");
	// root->right->right->left = new node(root->right->right, 0, "abba");
	// root->right->right->right = new node(root->right->right, 0, "abbb");

	// node::rrotate(root);
	// node::print(root);
	// node::lrotate(root);
	// node::print(root);


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