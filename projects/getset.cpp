#include <stdio.h>
#include <stdlib.h>
 

#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc == 1) {
		fprintf(stderr, "NO PARAMETERS!!!\n");
		exit(EXIT_FAILURE);
	}
	
	std::stringstream ss;
		ss << std::endl << "\t" << argv[1] << " get" << static_cast<char>(argv[2][0] - 32)
			<< (argv[2]+1)<< "()" << std::endl
			<< "\t{" << std::endl << "\t\treturn this->" << argv[2]
			<< ";" << std::endl << "\t}" << std::endl << std::endl
			<< "\tvoid" << " set" << static_cast<char>(argv[2][0] - 32)
			<< (argv[2]+1) << "(" << argv[1] << " " << argv[2] << ")"
			<< std::endl << "\t{" << std::endl << "\t\tthis->" << argv[2] << " = "
			<< argv[2] << ";" << std::endl << "\t}";

	std::cout << ss.str() << std::endl;
	
}

