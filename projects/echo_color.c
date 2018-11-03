#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int max = atoi(argv[2]);
	int i;
	for (i=0; i<max; i++) {
		fprintf(stdout, "%s", argv[1]);
	}
	return 0;
}
