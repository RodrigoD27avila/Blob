#include <iostream>
#include <fstream>

int main()
{
	std::fstream fs;
	fs.open("/home/rodrigo/foo.txt",
		std::fstream::in|std::fstream::out
			|std::fstream::app);
	if (fs.is_open()) {
		for (int i=0; i<10; i++) {
			fs << i << std::endl;
		}
		fs.flush();
		fs.close();
	} else {
		std::cerr << "Unable to open file." << std::endl;
	}
}
