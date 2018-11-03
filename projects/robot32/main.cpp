#include "vector.h"

int main()
{
	RVector<int>v(1, 1);
	rvector_pushback(&v, 10);
	rvector_pushback(&v, 10);
	rvector_pushback(&v, 10);
	rvector_pushback(&v, 10);
}
