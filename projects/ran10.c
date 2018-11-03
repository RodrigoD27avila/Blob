#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc <= 1) {
		fprintf(stderr, "USAGE: %s <len> <count>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *out  = fopen("out.bin", "wb");
	int  len   = atoi(argv[1]);
	int  count = atoi(argv[2]);

	int i;
	for (i=0; i<count; i++) {
		int r = rand() % 257;

		if (((i+1) % len) == 0) {
			fwrite("0", 1, 1, out);
			continue;
		}

		int  j;
		char buf[300];
		memset(buf, 0, 300);

		for (j=0; j<r; j++) {
			buf[j] = '1';
		}
		
		buf[j] = '0';
		fwrite(buf, 1, j+1, out);
	}

	fflush(out);
	fclose(out);

	return 0;
}
