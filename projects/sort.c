#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int nums[10];
	memset(&nums[0], 0, 10*sizeof(int));

	const char *bignum= argv[1];

	int i, j;
	for (i=0; bignum[i] != '\0'; i++) {
		nums[bignum[i]-'0'] += 1;
	}

	for (i=0; i<10; i++) {
		for (j=0; j < nums[i]; j++) {
			printf("%i", i);
		}
	}
	printf("\n");
	return 0;
}
