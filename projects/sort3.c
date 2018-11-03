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

	int i, j, k;
	for (i=0; i<len; i++) {
		occur[buff[i]]++;
	}

	for (i=0, k=0;i<256;i++) {
		for (j=0;j<occur[i]; j++) {
			buff[k++] = (char)i;
		}
	}

	gettimeofday(&t2,NULL);

	unsigned long long int usec = 1000000 * (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec);
	printf("%Lu\n", usec);

	for (i=0; i<len;i++) {
		printf("%c", buff[i]);
	}
	printf("\n");
}

