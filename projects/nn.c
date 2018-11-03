#include <stdio.h>

int main()
{
	unsigned long long int i, s=0;

	for (i=0; i<10000000; i++) {
		s+=i;
		printf("%llu - %llu\n", i, s);
	}
}
