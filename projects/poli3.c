#include <stdio.h>
#include <gmp.h>

static int stop;

static mpz_t         rops[3];
static unsigned char vops[3];

void start(int i)
{
	if (i< 3) {
		if (vops[i] == 3) {
			start(i+1);
			vops[i] = 0;
		} else {
			vops[i] += 1;
		}

		mpz_ui_pow_ui(rops[i], (unsigned long)vops[i], (unsigned long)i+1);
	} else {
		stop = 1;
	}
}

int main()
{
	mpz_t r;
	mpz_init(r);

	int i;
	for (i=0; i<3; i++) {
		mpz_init(rops[i]);
	}

	while(!stop) {
		mpz_set_ui(r, 0);
		start(0);
		for (i=0; i<3 && mpz_cmp_ui(rops[i], 0) > 0; i++) {
			mpz_add(r, r, rops[i]);
		}

		mpz_out_str(stdout, 10, r);
		printf("\n");
	}
}

