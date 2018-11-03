#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char **argv)
{
    if (argc < 2)
        return EXIT_FAILURE;

    unsigned long int small = atoll(argv[1]);

    mpz_t x;
    mpz_init(x);
    mpz_fac_ui(x, small);

    printf("%lu\n", mpz_sizeinbase(x, 2));

    return EXIT_SUCCESS;
}
