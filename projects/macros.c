#include "macros.h"

/*
	este método vai pegar o array g_myobjects e encher com os meus enemies 
*/
void init_enemies()
{
	int i=0;
	for (; i<MAX_ENEMIES; i++)
	{
		printf("iniciando objeto %i.\n", i);
		g_myobjects[i] = 7 * i;
	}
}

void init_shots()
{
	int i;
	for (i=MAX_ENEMIES; i< MAX_OBJECTS; i++)
	{
		printf("iniciando objeto %i.\n", i);
		g_myobjects[i] = 13 * 8;		
	}
}

void init_objects()
{
	/* nunca tire desta sequência ;)*/
	init_enemies();
	init_shots();
}

void my_descriptive_function(__in int a, __in int b,
		__out int *c) __no_raise
{
	*c = a + b;
}

/*
	é permitido declarar o main sem argc e argv

	é permitido declara o tipo de retorno do main como void
	mas é uma prática ruim, lembram-se do $?

*/
int main()
{
	init_objects();

	int i1 = 100, i2 = 899;

	printf("a soma de %i com %i é igual a %i.\n",
			i1, i2, SUM(i1, i2));

	int i3 = i1 + i2;
	int i4 = 40 + i3;	
	printf("a soma de %i com %i com %i com %i é igual a %i.\n",
			i1, i2, i3, i4, SUM4(i1, i2, i3, i4));

	printf("o maior número entre %i e %i é %i.\n",
			i1, i2, MAX(i1, i2));
	
	printf("o maior número entre %i, %i, %i e %i é %i.\n",
			i1, i2, i3, i4, MAX4(i1, i2, i3, i4));


	printf("%s\n", CONCAT_NSPACE(uma string, qualquer));
	printf("%s\n", CONCAT_WSPACE(uma string, qualquer));

	/*na realidade nem precisa dos de macros*/
	printf("isto é uma string muito" " longa "
		   "e eu separei ela em "
		   "várias linhas.\n");

	/*
		nota-se que é possível criar funções dentro de outras funções
		é possível criar struct, union e enum também.
	*/
	void this_is_a_function_with_a_very_very_long_name_1(int a, int b)
	{
		printf ("\n""<>""<>""<>""<>""<>""<>""<>""<>""<>""<>""\n");
	}
	
	void this_is_a_function_with_a_very_very_long_name_inside_main()
	{
		printf ("\n<<><><><><<>><><><>>\n");
	}

	call_LNFunction(1)(10, 30);
	call_LNFunction(inside_main)();

	__NOTHING
	__NOTHING
	__NOTHING
	__NOTHING
	__NOTHING
	__NOTHING


	int c = 0;
	my_descriptive_function(10, 20, &c);

	printf("O valor de c é %i\n", c);	

	return 0;
}
