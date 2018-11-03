#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int i, k;
	for (k=3889993; k<4992211; k+=2) {
		unsigned int s = 0;
		for (i=k; i > 1; ++s, i>>=1);
		printf("%lu - %lu\n", k, s);
	}
}
