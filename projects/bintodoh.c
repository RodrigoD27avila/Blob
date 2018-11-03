#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static void is_valid(const char *binnum);
static void check_lenght(const char *binnum);

int main(int argc, char **argv)
{
	if (argc <= 1) {
		fprintf(stderr, "USAGE: %s <binary number>", argv[0]);
		exit(EXIT_FAILURE);
	}

	const char *binnum = argv[1];
	
	check_lenght(binnum);
	is_valid(binnum)

	
}

static void is_valid(const char *binnum)
{
	size_t len = strlen(binnum);

	int i;
	for (i=0; i<len; i++) {
		if (binnum[i] != '1' && binnum[i] != '0') {
			fprintf(stderr, "Invalid binary!!\n");
			exit(EXIT_FAILURE);
		}
	}
}

static void check_lenght(const char *binnum)
{
	size_t len = strlen(binnum);
	if (len > 32) {
		fprintf(stderr, "Invalid length!!\n");
		exit(EXIT_FAILURE);
	}
}
