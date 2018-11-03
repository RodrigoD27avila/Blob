#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
	int i , *j;
	cout << typeid(i).name() << endl;
	cout << typeid(j).name() << endl;
	return 0;
}
