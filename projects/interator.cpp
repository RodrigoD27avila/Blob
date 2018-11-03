#include <iostream>
#include <vector>

int main()
{
	std::vector<int> myvec;
	myvec.push_back(1); myvec.push_back(2);
	myvec.push_back(3); myvec.push_back(4);
	myvec.push_back(5); myvec.push_back(6);
	myvec.push_back(7); myvec.push_back(8);

	std::vector<int>::const_iterator begin = myvec.begin();
	std::vector<int>::const_iterator end   = myvec.end();

	for (begin; begin != end; ++begin) {
		std::cout << *begin << std::endl;
	}
}

