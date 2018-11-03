#include <stdio.h>
#include <stdlib.h>
#include <dat.h>

int main(int argc, char **argv)
{
	FILE *dat = NULL;
	int error = 0;
	int i;
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
	
		printf("ID     : %s\n", id);
		printf("VERSION: %s\n", version);
		printf("ENTRIES: %i\n", (int)num_entries);
	
		fclose(dat);	
	}
	return 0;
}
