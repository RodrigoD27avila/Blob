#include <stdio.h>
#include "main_app.h"

int
main (int argc, char **argv)
{
	main_app app = {10,11,12};
	printf ("%i,%i,%i\n", app.a, app.b, app.c);
	return 0;
}
