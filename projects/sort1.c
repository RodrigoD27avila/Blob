#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

static char buff[65535L];
static int occur[256];

int main(int argc, char **argv)
{
	struct timeval t1, t2;
	size_t len;

	scanf("%s", buff);
	len = strlen(buff);

	gettimeofday(&t1,NULL);

	int i, j;
	for (i=0; i<len; i++) {
		for (j=0; j<buff[i]; j++) {
			occur[j]++;
		}
	}

	i = 0;
	while (occur[0] != 0) {
		int c=0, k;
		for (j=0, k=occur[0]; k == occur[j]; j++) {
			c++; occur[j] -= 1;
		}
		buff[i++] = c;
	}

	gettimeofday(&t2,NULL);

	unsigned long long int usec = 1000000 * (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec);
	printf("%Lu\n", usec);

	for (i=0; i<len;i++) {
		printf("%c", buff[i]);
	}
	printf("\n");
}

