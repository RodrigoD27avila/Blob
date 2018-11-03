#include "rdzcompress.h"

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("%s <input>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *in = fopen(argv[1], "rb");
	if (in == NULL) {
		exit(EXIT_FAILURE);
	}

	unsigned char byte1, byte2;
	int result;

	while (RDZ_GetBytes(&byte1, &byte2, in) == 0) {
		RDZ_TransformBytes(byte1, byte2, &result);
		RDZ_PrintString(result);
	}

	fclose(in);
	return 0;
}
