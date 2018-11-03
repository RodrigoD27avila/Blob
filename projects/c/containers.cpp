#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;

	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Cap : " << vec.capacity() << std::endl;

	vec.reserve(10);
	vec.resize(10);

	vec[0] = 100;
	vec[1] = 101;
	vec[2] = 102;

	std::cout << vec[0] << std::endl;
	std::cout << vec[1] << std::endl;
	std::cout << vec[2] << std::endl;
	
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Cap : " << vec.capacity() << std::endl;

	vec.reserve(10);
	vec.push_back(10);
	vec.resize(20);
	
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Cap : " << vec.capacity() << std::endl;

	for (int i=0; i<vec.size(); i++) {
		std::cout << vec[i] << std::endl;
	}

//	std::vector<int>::const_iterator i;
//	std::vector<int>::iterator i;
//	for (i=vec.begin(); i != vec.end(); i++) {
//	std::vector<int>::reverse_iterator i;
	std::vector<int>::const_reverse_iterator i;
	for (i=vec.rbegin(); i != vec.rend(); i++) {
		std::cout << (*i) << std::endl;
	}

	return 0;
}
