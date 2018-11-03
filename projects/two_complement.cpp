#include <string>
#include <iostream>
#include <bitset>

int main()
{
	char a = 16;
	char b = -16;

	std::bitset<8> c(a);
	std::bitset<8> d(b);
	std::bitset<8> e(a+b);


	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;

	return 0;
}
