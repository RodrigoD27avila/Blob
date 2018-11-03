#include <stdio.h>

int main()
{
    int e = 0, o = 0;

    int n;
    while (scanf("%d", &n) != EOF) {
        if ((n - (2*(n/2))) == 0) {
            e += 1;
        } else {
            o += 1;
        }
    }

    printf("EVEN = %i, ODD = %i\n", e, o);
}
