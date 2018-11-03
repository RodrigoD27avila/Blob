#include <stdio.h>
#include <stdlib.h>
#include <dat.h>

int main(int argc, char **argv)
{
	int error = 0;
	DAT dat;
	int i;

	if (argc <= 1) {
		printf("USAGE: %s <file [file [...]]>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((error = DAT_Init(&dat, "test.dat", "RODRIGO08092012",
		"RODRA", "001"))) {
		fprintf(stderr, "%s", DAT_GetErrorString(error));
		exit(EXIT_FAILURE);
	}

	for (i=1; i<argc; i++) { 
		if ((error = DAT_PushBack(&dat, argv[i])) < 0) {
			fprintf(stderr, "%s:\n%s\n", argv[i],
				DAT_GetErrorString(error));
			exit(EXIT_FAILURE);
		}
	}

	if ((error = DAT_Write(&dat)) < 0) {
		fprintf(stderr, "%s", DAT_GetErrorString(error));
		exit(EXIT_FAILURE);
	}

	DAT_Destroy(&dat);
	
	return 0;
}
