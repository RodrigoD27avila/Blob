#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

void test_vector()
{
	
	vector<int> vec(100, 0);
	cout << "at()       : " << vec.at(10) << endl;
	cout << "operator []: " << vec[10]    << endl;
	cout << "size()     : " << vec.size() << endl;
	try {
		cout << "at()       : " << vec.at(1000) << endl;
	}
	catch (out_of_range& ex) {
		cout << "No Problem =) " << endl;
	}
}

int main()
{
	test_vector();
	return 0;
}
