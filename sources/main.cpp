#include "vector.hpp"

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

int	main(void)
{
	ft::vector<std::string>				vec;
	ft::vector<std::string>				vec2;
	ft::vector<std::string>::iterator	it;
	// ft::vector<int>::reverse_iterator	it;

	// print(vec);
	// vec.reserve(200);
	// print(vec);
	// vec.reserve(10);

	for (int i = 0; i < 10; i++)
		vec.push_back("lol");

	// vec.erase(vec.begin() + 5, vec.begin() + 10);

	// for (int i = 0; i < 20; i++)
	// 	vec2.push_back((i + 1) * 20);

	// print(vec);
	// vec.insert(vec.begin() + 5, 42);
	// print(vec);

	// vec.swap(vec2);

	// vec.pop_back();

	// for (it = vec.erase(vec.begin() + 5, vec.begin() + 10); it != vec.end(); it++)
	// 	std::cout << *it << "\n";

	vec.insert(vec.begin() + 2, 5, "hello");

	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << "\n";

	// for (it = vec.rbegin(); it != vec.rend(); it--)
	// 	std::cout << *it << "\n";

	// for (it = vec2.begin(); it != vec2.end(); it++)
	// 	std::cout << *it << "\n";

	return (0);
}