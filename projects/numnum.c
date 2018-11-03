#include <stdio.h>

#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a > b) ? a : b)

#define MIN2(a, b, c) ((a < MIN(b, c)) ? a : MIN(b , c))
#define MAX2(a, b, c) ((a > MAX(b, c)) ? a : MAX(b , c))


int main()
{
	static int sum[28];

	int i, j, k;
	for (i=1;i<=10;i++) {
	for (j=1;j<=10;j++) {
	for (k=1;k<=10;k++) {

	printf("S%3i %3i %3i Mi%3i Ma%3i %i%i%i\n",
		i+j+k-3,
		i+j-k,
		i-j+k,
		MIN2(i,j,k)-1,
		MAX2(i,j,k)-1,
		i-1,
		j-1,
		k-1);

		sum[i+j+k-3]++;

	}
	}
	}

	for (i=0; i<28; i++) {
		printf("%2i - %2i\n", i, sum[i]);
	}

	return 0;
}


