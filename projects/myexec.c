#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main(int argc ,char **argv)
{
	if (argc <= 2)
	{
		fprintf(stderr, "USAGE %s <path-to-program> [arg1[arg2[...]]]\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}


	execv(argv[1], argv);
	perror("execv");
	return 0;
}
