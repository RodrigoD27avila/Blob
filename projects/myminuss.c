#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define BIGINT_SIZE 4096

typedef unsigned int *bigint;

bigint bigint_new(void)
{
	bigint n = malloc(BIGINT_SIZE);
	memset(n, 0, BIGINT_SIZE);
	return n;
}

inline void bigint_increment(bigint b, int i)
{
	b[i] += 1;
	if (b[i] == 0)
		bigint_increment(b, i+1);
}

void bigint_print(bigint b)
{
	unsigned int i;
	for (i=0; b[i] != 0; i++) {
		printf("%lu ", b[i]);
	}
	printf("\n");
}

bigint b;

void sig_handler(int signum)
{
	bigint_print(b);
}

int main()
{

	signal(SIGUSR1, sig_handler);

	b = bigint_new();
	for (;;) {
		bigint_increment(b, 0);
	}
}
