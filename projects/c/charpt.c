#include <stdio.h>

/**
	Sobre Ponteiros:
		int dados = 8;
		int *ponteiro = &dados;

		ponteiro  --> contém o endereço de dados 
			>>> 0x674322

		*ponteiro --> contém o valor de dados (que é o valor que contém o endereço onde ele aponta)
			>>> 8

		&ponteiro --> contém o endereço de ponteiro (que é o valor do endereço que contém o endereço de dados)
			>>> 0x233202
**/

void p_int()
{
	//Ponteiros de int
	int i = 0;
	int my_array[] = {1, 2, 3, 4, 5, 6};
	int *p_arr = &my_array[0];

	for (; i < 6; i++) {
		printf ("%p  --  ", p_arr);
		printf ("%i\n", *p_arr);
		p_arr += 1;
	}
}

void p_char()
{
	//ponteiro de char
	int i = 0;
	char str[] = "Rodrigo D'avila programa em C!!";
	char *p_str = &str[0];

	for (; i < (sizeof(str) - 1); i++) {
		printf ("%p  --  ", p_str);
		printf ("%c\n", *p_str);
		p_str += 1;
	}
	printf("\n------##------\n");
	printf ("%s = %i bytes.\n", str, sizeof(str));
}


int
main (void)
{

	void (*p_func)();

	p_func = p_int;
	(*p_func)();

	p_func = p_char;
	(*p_func)();

	printf ("E = %p, T = %i\n", &p_int, sizeof(p_int));
	printf ("E = %p, T = %i\n", &p_char, sizeof(p_char));
	return 0;
}
