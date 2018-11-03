#include <stdio.h>
#include <stdlib.h>

#define MAX 25


int table[MAX] = {1,2,3,4,5,4,5,3,5,4,0,9,3,4,5,6,7,1,2,3,4,5,6,7,8};

int main()
{
    int i, k=0;
    while (1) {
        for (i=1; i<MAX; i++) {
                if (table[i] == k) {
                    table[i] = table[i-1];
                } else if (table[i] == table[i-1]) {
                    table[i] = k;
                }
        }

        k+=1;
        if (k>=10) k=0;

        for (i=0; i<MAX; i++) {
            printf("%i", table[i]);
        }
        printf("\n");
    }
}
