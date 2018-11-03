#include <iostream>
#include <bitset>

int main()
{
	std::bitset<1000> bits;
	bits.set(2, 1);

	std::cout << bits << std::endl;
}
