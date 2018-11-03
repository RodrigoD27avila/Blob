#include <stdio.h>
#include <gmp.h>
#include <signal.h>

static mpz_t p, r;

void signal_handler(int signum)
{
}

int main()
{
	signal(SIGUSR1, signal_handler);

	mpz_inits(p, r, NULL);

	for (;;) {
		mpz_add_ui(p, p, 1);
		mpz_pow_ui(r, p, 2);
		mpz_add(r, r, p);
		mpz_out_str(stdout, 10, r);
		printf("\n");
	}
}
