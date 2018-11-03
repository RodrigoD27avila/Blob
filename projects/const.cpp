#include <iostream>

int main()
{
	int numero[10] = {0,1,2,3,4,5,6,7,8,9};
	int *numero2 = numero;
	numero2[0] = 3;
	int *numero3 = numero;
	numero3[0] = 4;
}
