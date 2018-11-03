#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a = 56798;
	int b = 23378;
	int c = 99489;
	FILE *out = fopen("teste.int", "wb+");
	fwrite((char *)&a, 1, sizeof(int), out);
	fwrite((char *)&b, 1, sizeof(int), out);
	fwrite((char *)&c, 1, sizeof(int), out);
	fflush(out);
	fclose(out);

	int j;
	FILE *in = fopen("teste.int", "rb");
	fseek(in, 8, SEEK_SET);
	fread((char *)&j, 1, sizeof(int), in);
	fclose(in);

	printf("%i\n", j);

	return 0;
}
