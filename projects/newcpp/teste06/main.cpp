#include <iostream>
using namespace std;

#define MAX_ELEM 3

template <class T>
class MyArray {
private:
	unsigned int size;
public:
	MyArray()
		: size(0)
	{}

	MyArray(unsigned int size)
		: size(size)
	{}
};


int main()
{
	int *arr = new int[MAX_ELEM]();

	for (int i=0; i< MAX_ELEM; i++) {
		cin >> arr[i];
	}

	delete[] arr;	
}
