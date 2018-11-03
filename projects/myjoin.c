#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *f1 = fopen(argv[1], "rb");
	FILE *f2 = fopen(argv[2], "rb");
	int i=1;

	const char buff1[1000];
	const char buff2[1000];

	while (fscanf(f1, "%s", &buff1[0]) != EOF
		&& fscanf(f2, "%s", &buff2[0]) != EOF) {
		fprintf(stdout, "%i- %s - %s\n", i, buff1, buff2);
		fflush(stdout);
		i+=1;
	}

	fclose(f1);
	fclose(f2);
}
