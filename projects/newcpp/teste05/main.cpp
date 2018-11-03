#include "template.h"

#include <iostream>
using std::cout;

int main()
{
	Teste<int> t(10, 50);
	cout << t.sum() << "\n";
}
