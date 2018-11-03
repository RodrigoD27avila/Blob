#include <iostream>
#include <bitset>

int main()
{
	int i;
	for (i=0; i<256; i++) {
		int p = 0;
		if (i & 0x01) ++p;
		if (i & 0x02) ++p;
		if (i & 0x04) ++p;
		if (i & 0x08) ++p;
		if (i & 0x10) ++p;
		if (i & 0x20) ++p;
		if (i & 0x40) ++p;
		if (i & 0x80) { ++p; std::cout << "SF|"; }

		if (i==0) {
			std::cout << "ZF|PF";
		}
		else if (!(p & 0x1)) {
			std::cout << "PF";

		} else {
			std::cout << "0";
		}

		std::cout << ", ";
		if (i != 0 && (i % 16) == 0) {
			std::cout << std::endl;
		}
	}
}
