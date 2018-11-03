#include <stdio.h>
#include <string.h>
#include <gmp.h>

int main(int argc, char **argv)
{
	int nums[256];
	memset(&nums[0], 0, 256*sizeof(int));

	char buffer[4096];
	size_t i, bytes_read;
	while ((bytes_read = fread(buffer, 1, 4096, stdin)) > 0) {
		for (i=0; i < bytes_read; i++) {
			nums[buffer[i]-'0'] += 1;
		}
	}

	mpz_t mynum;
	mpz_init_set_str(mynum, "1", 10);
	for (i=0; i < 256; i++) {
		for (; nums[i] > 0; nums[i] -= 1) {
			mpz_mul_ui(mynum, mynum, i+1);
		}
	}
	mpz_out_str(stdout, 10, mynum);
	printf("\n");
	mpz_clear(mynum);
	return 0;
}
