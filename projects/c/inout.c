#include <stdio.h>

int
main ()
{
	FILE *f = fopen ("/home/rodrigo/log", "wa");
	
	fprintf (f, "Rodrigo D'avila\n");
	fprintf (f, "Rodrigo D'avila\n");
	fprintf (f, "Rodrigo D'avila\n");
	fprintf (f, "Rodrigo D'avila\n");

	fflush (f);
	fclose (f);
	
	return 0;
}
