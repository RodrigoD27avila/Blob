#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int main()
{
	try {
		vector<int> v;
		v.at(100);
	}
	catch (out_of_range &ex) {
		cerr << ex.what() << endl;
	}
}
