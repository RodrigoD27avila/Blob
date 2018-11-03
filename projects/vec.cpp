#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = {10, 10, 10};
	std::vector<int> b = {11, 11, 11};

	v = b;

	for (auto &j : v) {
		std::cout << j << " ";
	}
}
