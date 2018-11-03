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
		DAT_Sint32 size;
		DAT_Sint64 offset;
		memset(name, 0, DAT_NAME_SIZE);
		

		for (j=0; j<num_entries; j++) {
			if ((error = DAT_GetEntryInfo(j, name,
				&size, &offset, dat)) < 0) {
				fprintf(stderr, "%s\n",
					DAT_GetErrorString(error));
				fclose(dat);
				exit(EXIT_FAILURE);
			}

			printf("INDEX : %i\n", j);
			printf("NAME  : %s\n", name );
			printf("SIZE  : %i\n", size);
			printf("OFFSET: %li\n\n", (long int)offset);
		}
	
		fclose(dat);	
	}
	return 0;
}
