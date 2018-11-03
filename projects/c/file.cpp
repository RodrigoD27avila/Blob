#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	ofstream of;
	of.open("test.dat", ios::binary);

	if (!of) {
		cerr << "Unable to open text.dat" << endl;
		exit(EXIT_FAILURE);
	}

	for(int i=0; i < 100; i++) {
		of.write((char *)&i, sizeof(int));
	}

	of.flush();
	of.close();
	
	return 0;
}
