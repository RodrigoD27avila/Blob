#include <stdio.h>
#include <stdlib.h>
#include <dat.h>

int main(int argc, char **argv)
{
	FILE *dat = NULL;
	int error = 0;
	int i, j;
	for (i=1; i<argc; i++) {
		char id[DAT_ID_SIZE];
		char version[DAT_VERSION_SIZE];
		DAT_Sint32 num_entries;

		dat = fopen(argv[1], "rb");
		if (dat == NULL) exit(EXIT_FAILURE);

		if ((error = DAT_GetHeaderInfo(id, version,
			&num_entries, dat)) < 0) {

			fprintf(stderr, "%s\n", DAT_GetErrorString(error));
			fclose(dat);
			exit(EXIT_FAILURE);
		}

		char name[DAT_NAME_SIZE];
		memset(name, 0, DAT_NAME_SIZE);

		for (j=0; j<num_entries; j++) {
			if ((error = DAT_GetEntryInfo(j, name,
				NULL, NULL, dat)) < 0) {
				fprintf(stderr, "%s\n",
					DAT_GetErrorString(error));
				fclose(dat);
				exit(EXIT_FAILURE);
			}

			printf("%i = %s\n", j, name);
		}
	
		fclose(dat);	
	}
	return 0;
}
