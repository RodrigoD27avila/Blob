#include <stdio.h>

int main()
{
	int adicao = 400 ^ 100;
	printf ("Adição        = %i\n", adicao);

	int subtracao = 400 + (~100) + 1;
	printf ("Subtração     = %i\n", subtracao);
	

	int multiplicacao = 0 ^ (400 < 1) ^ 0 ^ (100 << 3);
	printf ("Multiplicação = %i\n", multiplicacao);
	return 0;
}
