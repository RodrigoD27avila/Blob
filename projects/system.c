#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc <= 1)
		exit(EXIT_FAILURE);

	printf("executing %s...\n", argv[1]);

	if (system(argv[1]) > 0)
	{
		printf ("Failure!!\n");
		exit(EXIT_FAILURE);

	}
	
	return 0;
}
