#include <stdio.h>
#include <gmp.h>

void pow_mpz_c(mpz_t *ret, mpz_t base, mpz_t exp)
{
    mpz_t result;
    mpz_init(result);
    mpz_set(result, *ret);

    if (mpz_cmp_ui(result, 0) <= 0)
        mpz_set_ui(result, 1);

    mpz_mul(result, result, base);

//    gmp_printf("%Zd\n", result);
    mpz_set(*ret, result);
}

void pow_mpz(mpz_t *ret, mpz_t base, mpz_t exp)
{
    mpz_t i, result;

    mpz_init(result);
    mpz_set_ui(result, 1);

    for (mpz_init(i); mpz_cmp(i, exp) < 0; mpz_add_ui(i, i, 1))
    {
        mpz_mul(result, result, base);
    }

    mpz_set(*ret, result);
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        printf("Params: base num_base num unit rep\n");
        return 1;
    }

    mpz_t unit, rep, base, num_base, result, power, num,c1, c2, c3, c4, i;

    mpz_init(unit);
    mpz_init(rep);
    mpz_init(base);
    mpz_init(num_base);
    mpz_init(result);
    mpz_init(power);
    mpz_init(num);

    mpz_set_str(base,     argv[1], 10);
    mpz_set_str(num_base, argv[2], 10);
    mpz_set_str(num,      argv[3], 10);
    mpz_set_str(unit,     argv[4], 10);
    mpz_set_str(rep,      argv[5], 10);

  //  gmp_printf("%Zd\n", base);
  //  gmp_printf("%Zd\n", num_base);
  //  gmp_printf("%Zd\n", unit);
  //  gmp_printf("%Zd\n", rep);

//    if (mpz_cmp(unit, rep) <= 0)
//        return 1;

    mpz_sub(power, unit, rep);

    mpz_init(c1);
    mpz_init(c2);
    mpz_init(c3);
    mpz_init(c4);

    pow_mpz(&c2, base, power);

    for (mpz_init(i); mpz_cmp(i, unit) < 0; mpz_add_ui(i, i, 1))
    {
        pow_mpz_c(&c1, num_base, unit);

        mpz_mul(c3, c2, c1);
        mpz_mul(c4, num, c1);

        mpz_add(result, result, c3);
        mpz_add(result, result, c4);
    //    gmp_printf("%Zd\n", result);
    }

    gmp_printf("%Zd\n", result);

    mpz_clear(unit);
    mpz_clear(rep);
    mpz_clear(base);
    mpz_clear(num_base);
    mpz_clear(result);
    mpz_clear(power);
    mpz_clear(num);
    mpz_clear(c1);
    mpz_clear(c2);
    mpz_clear(c3);
    mpz_clear(c4);
    mpz_clear(i);
    return 0;
}
