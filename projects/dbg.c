#include <stdio.h>

const static int i = 900;

void print_i()
{
	printf("value of i = %i\n", i);
	return;
}

int main()
{
	int a = i;
	int b = 500;
	int c = (a - b) + 10;
	print_i();
	printf("%i\n\n", c);
	return c;
}
