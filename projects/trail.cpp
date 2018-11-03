#include <iostream>

template<class Input, class Predicate>
	void for_all (Input in, Predicate pred)
{
	auto first = in.begin();
	auto last  = in.end();

	for (; first != last; ++first) {
		pred(*first);
	}	
}

int main()
{
	std::string foo("Rodrigo D'avila");
	for_all(foo, [](char c) {std::cout << c << std::endl;});

	auto l = [](int j) {
		return j+1;
	};

	std::cout << l(10) << std::endl;
}
