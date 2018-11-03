#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	stringstream ss;
	ss << "Rodrigo " << "D'avila" << 42;
	
	string sr =ss.str();
	transform(sr.begin(), sr.end(), sr.begin(), ::toupper);

	cout << sr << endl;
}
