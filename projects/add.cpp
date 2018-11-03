#include <iostream>
#include <bitset>

int main()
{
	unsigned char a = 240;
	unsigned char b = 19;
	unsigned char c = a+b;
	unsigned short c2 = a+b;

	unsigned char g = (((~(0b01000000^0b10000000)&0x80)>>5)&0x4);
	std::cout << "G = " << int(g) << std::endl;

	std::bitset<8> b1(a);
	std::bitset<8> b2(b);
	std::bitset<8> b3(c);
	std::bitset<16> b4(c2);

	if (((a^b)&(a^c))&0x80) {
		std::cout << "Overflow!!" << std::endl;
	} else {
		std::cout << "NOT Overflow!!" << std::endl;
	}

	std::cout << "a  = " << b1 << std::endl;
	std::cout << "b  = " << b2 << std::endl;
	std::cout << "c  = " << b3 << std::endl;
	std::cout << "c2 = " << b4 << std::endl;
}
