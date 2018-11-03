#include <iostream>
using namespace std;

int
main (int argc, char **argv)
{
	int v = 9;

	int *p1 = &v;
	int& r1 = v;
	int v1 = v;

	int *p2 = p1;
	int& r2 = *p1;
	int v2 = *p1;

	int *p3 = &r1;
	int& r3 = r1;
	int v3 = r1;
	
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v3 << endl;
	cout << "----" << endl;
	cout << *p1 << endl;
	cout << *p2 << endl;
	cout << *p3 << endl;
	cout << "----" << endl;
	cout << r1 << endl;
	cout << r2 << endl;
	cout << r3 << endl;
	cout << "----" << endl;

	return 0;
}
