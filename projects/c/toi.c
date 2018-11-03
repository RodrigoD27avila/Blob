#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char **argv)
{
	char* cnum = "123";

	int inum = atoi (cnum);
	float fnum = atof (cnum);

	printf ("%i\n", inum);
	printf ("%f\n", fnum);

	return 0;
}
