#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *arq;
	char c;

	arq = fopen("infos.dat", "r");
	if (!arq) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while (1) {

		if (feof(arq)) break;

		c = getc(arq);
		if (c >= 32) 
			printf("%c = %i\n", c , (int)c);
	}

	fclose(arq);
	return 0;
}
