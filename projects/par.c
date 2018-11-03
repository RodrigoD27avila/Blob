#include <stdio.h>

int impar(int n);
int par(int n);

int impar(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;


	return par(n-1);
}
int par(int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 0;


	return impar(n-1);
}

int main()
{
	printf("%i\n", impar(10));
}
