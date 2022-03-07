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
	ft::vector<int> vector;

	print(vector);
	vector.reserve(200);
	print(vector);
	vector.resize(100, 41);
	print(vector);
	vector.resize(150, 42);
	print(vector);
	vector.resize(50, 43);
	print(vector);

	return (0);
}