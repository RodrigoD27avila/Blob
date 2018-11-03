#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdint>

int main()
{
	std::ifstream tibia_dat;
	tibia_dat.open("Tibia.dat");

	if (!tibia_dat.is_open()) {
		std::cerr << "unable to open Tibia.dat" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	uint32_t version = 0;
	tibia_dat.read((char *)&version, 4);

	uint16_t typescount[5] = {0, 0, 0, 0, 0};
	tibia_dat.read((char *)typescount, 10);

	int i;
	for (i=0; i<5; i++) {
		std::cout << "types: "<< typescount[i] << std::endl;
	}
}
