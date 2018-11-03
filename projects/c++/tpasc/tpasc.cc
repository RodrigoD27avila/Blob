#include <iostream>
using namespace std;

double
fact (double n)
{
	return (n > 1) ? n * fact (n - 1) : 1;
}

double
ncr (int n, int r)
{
	return fact (n) / (fact (r) * fact (n - r));
}

int
main()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << ncr (i, j) << ' ';
			cout << endl;
	}
}
