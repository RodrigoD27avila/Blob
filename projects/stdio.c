#include <stdio.h>

int main()
{
	FILE *myfile = stdin;
	fflush(myfile);
	fclose(myfile);
}
