#include <stdio.h>
#include <stdlib.h>

#include <dat.h>


int main(int argc, char **argv)
{
	int error = 0;
	DAT_Sint32 size;
	int i;
	for (i=1; i<argc; i++) { 
		if ((error = DAT_GetFileSize(&size, argv[i])) < 0) {
			fprintf(stderr, "%s:\n%s\n", argv[i],
				DAT_GetErrorString(error));
			exit(EXIT_FAILURE);
		}
		printf("%s: %i\n", argv[i], size);
	}
	
	return 0;
}
