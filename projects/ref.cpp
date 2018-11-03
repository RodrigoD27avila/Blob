#include <iostream>
using namespace std;

class Foo {
public:
	int *nums;

	Foo() {
		cout << "Create Foo" << endl;
		nums = new int[10];
		nums[6] = 11;
	}

	~Foo() {
		cout << "Delete Foo" << endl;
		delete[] nums;
	}
};

Foo get_a_foo() {
	Foo f;
	cout << "my pointer  = " << f.nums << endl;
	return f;
}

int main() {
	Foo f = get_a_foo();
	cout << f.nums[6] << endl;
	cout << "the pointer = " << f.nums << endl;
}
