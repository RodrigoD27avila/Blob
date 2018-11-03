#include <stdio.h>

struct part
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

union upart
{
    struct part p;
    const char c[24];
};

union fuu
{
    unsigned int i;
    const char c[8];
};

int main()
{
    union fuu u;
    u.i = 0b1111111111111111111;

    printf("%s\n", u.c);

    return 0;
}
