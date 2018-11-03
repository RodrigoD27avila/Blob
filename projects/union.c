#include <stdio.h>

union uuu
{
    int x;
    char y;
};

int main()
{
    union uuu u;
    u.x = 10;
    u.y = 20;
    u.x = 30;

    printf ("%i\n", u.x);
    printf ("%c\n", u.y);
    return 0;
}
