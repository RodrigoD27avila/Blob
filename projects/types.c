#include <stdio.h>

int main()
{
        printf("%u\n", sizeof(char) * 8);
        printf("%u\n", sizeof(short) * 8);
        printf("%u\n", sizeof(int) * 8);
        printf("%u\n", sizeof(long) * 8);
        printf("%u\n", sizeof(long long) * 8);
        printf("%u\n", sizeof(float) * 8);
        printf("%u\n", sizeof(double) * 8);
        printf("%u\n", sizeof(long double) * 8);

		printf ("%Lu\n", 10);
        return 0;
}

