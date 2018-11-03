#include <stdio.h>
#include <stdlib.h>
#include <dat.h>

int write_to_file(char *name, DAT_Sint64 pos, int size, FILE *dat)
{
	int error = 0;

	FILE *out = NULL;
	out = fopen(name, "wb+");
	if (out == NULL) {
		return -DAT_EFILE;
	}
	
	const int len = 500;

	char buffer[len];
	int  bytes = 0;
	memset(buffer, 0, len);

	while (bytes < size) {
		int bytesrw = ((bytes+len)<size) ? len : (size-bytes);

		if ((error = DAT_GetData(buffer, bytesrw, pos, dat)) < 0) {
			goto end_with_error;
		}

		if ((fwrite(buffer, 1, bytesrw, out)) <= 0) {
			error = -DAT_EWRITE;
			goto end_with_error;	
		}

		bytes += len;
		pos   += len;		
	}

	fflush(out);
	fclose(out);

	return 0;

end_with_error:
	fclose(out);
	return error;	
	
}

int main(int argc, char **argv)
{
	FILE *dat = NULL;
	int error = 0;
	int i, j;

	for (i=1; i<argc; i++) {
		DAT_Sint32 num_entries;

		dat = fopen(argv[1], "rb");
		if (dat == NULL) exit(EXIT_FAILURE);

		if ((error = DAT_GetHeaderInfo(NULL, NULL,
			&num_entries, dat)) < 0) {
			goto end_with_error;
		}

		int size = 0;
		char name[DAT_NAME_SIZE];
		memset(name, 0, DAT_NAME_SIZE);
		DAT_Sint64 offset;

		for (j=0; j<num_entries; j++) {
			if ((error = DAT_GetEntryInfo(j, name,
				&size, &offset, dat)) < 0) {
				goto end_with_error;
			}

			if ((error = write_to_file(name, offset, size,
				dat)) < 0) {
				goto end_with_error;
			}
		}
	
		fclose(dat);	
	}
	return 0;

end_with_error:
	fprintf(stderr, "%s\n", DAT_GetErrorString(error));
	fclose(dat);
	exit(EXIT_FAILURE);
	return 0;
}
