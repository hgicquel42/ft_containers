#include "vector.hpp"

#include <iostream>

using namespace std;

void	print(ft::vector<int>& vector)
{
	cout << "-----------" << "\n";
	cout << vector.size() << "\n";
	cout << vector.capacity() << "\n";
	cout << vector.max_size() << "\n";
	cout << "-----------" << "\n";
}

int	main(void)
{
	ft::vector<int>				vec;
	ft::vector<int>				vec2;
	// ft::vector<int>::iterator	it;
	ft::vector<int>::reverse_iterator	it;

	// print(vec);
	// vec.reserve(200);
	// print(vec);
	
	for (int i = 0; i < 20; i++)
		vec.push_back(i);

	// vec.erase(vec.begin() + 5, vec.begin() + 10);

	// for (int i = 0; i < 20; i++)
	// 	vec2.push_back((i + 1) * 20);

	// vec.swap(vec2);

	// vec.pop_back();

	// for (it = vec.erase(vec.begin() + 5, vec.begin() + 10); it != vec.end(); it++)
	// 	std::cout << *it << "\n";

	std::cout << "lol\n";

	for (it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << "\n";

	// for (it = vec.rbegin(); it != vec.rend(); it--)
	// 	std::cout << *it << "\n";

	// for (it = vec2.begin(); it != vec2.end(); it++)
	// 	std::cout << *it << "\n";

	return (0);
}