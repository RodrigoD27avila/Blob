#include <iostream>
#include <algorithm>
#include <array>

int main()
{
	std::array<int, 10> foo;
	std::for_each(foo.begin(), foo.end(), [] (int i) {
		std::cout << i << std::endl;
	});
}
