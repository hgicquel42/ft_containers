#include "vector.hpp"

#include <iostream>

using namespace std;

void	print(ft::vector<int>& vector)
{
	cout << "-----------" << "\n";
	cout << vector.size() << "\n";
	cout << vector.capacity() << "\n";
	cout << vector.max_size() << "\n";
}

int	main(void)
{
	ft::vector<int> vec;

	print(vec);
	vec.reserve(200);
	print(vec);
	vec.resize(100, 41);
	print(vec);
	vec.resize(150, 42);
	print(vec);
	vec.resize(50, 43);
	print(vec);

	ft::vector<int>::iterator	it;
	for (it = vec.begin() + 25; it != vec.end(); it++)
		std::cout << *it << "\n";

	return (0);
}