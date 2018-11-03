#include <iostream>
#include <exception>

int main()
{
	try {
		std::cout << "Hello C++" << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
