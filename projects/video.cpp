#include <iostream>

template <class Init>
	void init(Init func)
{
	func();
}

int main()
{
	init( [&] () {
		std::cout << "Initialized" << std::endl;
	});
}
