#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "USAGE: %s <input>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char buff[4096];
	FILE *input = fopen(argv[1], "rb");
	if (input == NULL) {
		fprintf(stderr, "Unable to open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	unsigned int order[256];
	memset(&order[0], 0, 256 * sizeof(unsigned int));

	size_t read = 0;
	unsigned int i;
	do {
		read = fread(&buff[0], 1, 4096, input);
		if (ferror(input)) {
			fprintf(stderr, "error read file.\n");
			fclose(input);
			exit(EXIT_FAILURE);
		}

		for (i=0; i<read; i++) {
			order[(int)buff[i]] += 1;
		}

	} while (!feof(input));

	unsigned int sum = 0;
	for (i=0; i<256; i++) {
		unsigned int n = (unsigned int)order[i];
		printf("%u = %u\n", i, n);
		sum += n;
	}

	printf("sum = %u\n", sum);
}
