#include <stdio.h>
#include <gmp.h>

int main()
{
	mpz_t i, s, t, j, d;
	mpz_inits(i, s, t, j, d, NULL);
	mpz_set_ui(t, 2);
	mpz_set_ui(j, 1);

	for (mpz_set_si(i, 0);  ; mpz_add_ui(i, i, 1)) {
		if (mpz_cmp(t, s) <= 0) {
			mpz_sub(d, s, t);
			printf("2**");
			mpz_out_str(stdout, 10, j);
			printf(" = ");
			mpz_out_str(stdout, 10, t);
			printf(" | ");
			mpz_out_str(stdout, 10, i);
			printf(" | ");
			mpz_out_str(stdout, 10, s);
			printf(" | ");
			mpz_out_str(stdout, 10, d);
			printf("\n");
			mpz_mul_ui(t, t, 2);
			mpz_add_ui(j, j, 1);
		}

		mpz_add(s, s, i);
	}

}
