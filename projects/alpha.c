#include <stdio.h>

static char *alpha = "ABCDEFGHabcdefgh";

int main()
{
    int i, j;
    for (i=0; i<256; i++) {
        int c = i % 16;
        printf("\"%c", alpha[c]);
        int lim = i / 16;
        for (j=0; j<lim; j++) {
            printf("%c", alpha[c]);
        }
        printf("\", ");
    }
}
