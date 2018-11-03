#include <iostream>

int main()
{
	uint8_t OR_table[65535L];
	int i, j, k=0;
	for (i=0; i<256; i++) {
		for (j=0; j<256; j++, k++) {
			OR_table[k] = i|j;
			std::cout << static_cast<int>(OR_table[k]) << std::endl;
		}
	}
}
