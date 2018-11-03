#include <gmp.h>

int main(int argc, char **argv)
{
    mpz_t e;
    mpz_init(e);
    mpz_set_str(e, argv[1], 10);

    mpz_ui_pow_ui(e, 2, mpz_get_ui(e));
    mpz_ui_pow_ui(e, 2, mpz_get_ui(e));

    gmp_printf("%Zd\n", e);
    mpz_clear(e);
    return 0;
}
