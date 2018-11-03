#include <iostream>
#include <list>

int main()
{
	std::list<int> foo {1,2,3,4,5,6,7,8,9,10};

	for (auto it = foo.begin(); it !=foo.end(); it++) {
		std::cout << *it << std::endl;
	}
	
	for (auto &i : foo) {
		std::cout << i << std::endl;
	}
	
}
