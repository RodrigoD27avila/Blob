#include <stdio.h> /*Para usar o printf*/

int main(int argc, char **argv)
{
	/*
		exemplo de utilização do argc e argv
		mais informações abaixo.
	*/

	if (argc <= 1)
	{
		printf("USAGE: %s <argumento 1> [argumento 2 [argumento 3 ...]]\n",
			argv[0]);
		return -1;
	}

	/*
		-- Tipos de dados inteiros
		
		tipo      | tamanho em bits

		char      | 8
		short     | 16
		int       | 32
		long      | 32 ou 64
		long long | 64

		mais informações:
		man stdint.h

		-- Tipos de dados de ponto flutuante

		tipo        | tamanho em bits

		float       | 32
		double      | 64
		long double | 128 ou 64
		
		mais informações:
		man float.h

		-- Modificadores de sinal

		signed <tipo de dado>
		unsigned <tipo de dado>
	    por padrão quando declaramos um tipo ele é sempre signed

		-- Ponteiros

		para se declarar um ponteiro:

		<tipo dado> *<nome variavel>

		estilos de declaração ponteiros ex:
		
		1) void *myvoid;
		2) void* myvoid;
		3) void * myvoid;

		o estilo mais usado é o do numero 1

	*/

	char  mychar  = 'R';
	char  *mystring = "isso é uma string!!";
	short myshort = 3447;
	int   myint   = -6772;
	long  mylong  = 99991122;

	long long myllong = -99922233332;

	/*
		-- Usando o printf

		definição simples:
			printf (const char *format, ...);

		formato de tipos de dados:

		%c    char
		%s    string

		%i    int / short
		%u    unsigned int / unsigned short
	
		%ld   long
		%lu   unsigned long

		%Ld  long long
		%Lu  unsigned long long
			
	*/

	printf ("o valor de mychar é %c\n", mychar);
	printf ("o valor de mystring é %s\n", mystring);
	printf ("o valor de myshort é %d\n", myshort);
	printf ("o valor de myint é %i\n", myint);
	printf ("o valor de mylong é %ld\n", mylong);
	printf ("o valor de myllong é %Ld\n",myllong);

	/*
		-- argc e argv

		Por definição a função main em C recebe dois parâmetros,
		o argc e o argv.

		o argc é um int que contem a quantidade de parâmetros passado
		o argv é um ponteiro de lista de string

		obs:o valor de argc numca vai ser 0 porque
			o argv[0] sempre contém o nome do programa.

			 ex:
			 ./meuprograma arg1 arg2 arg3
			 o valor em argc vai ser 4
			 argv[0] = ./meuprograma
			 argv[1] = arg1
			 argv[2] = arg2
			 argv[3] = arg4
	*/


	/*
		Boas práticas:
		Sempre declare o contador fora do for
		como no Ex1 abaixo.
		

		Ex1)
			int i;
			for (i=0; i < 10; i++)

		Ex2)
			for (int i=0; i < 10; i++)
		
		c99 suporta o contador dentro
		mas a maneira mais utilizada é
		com ele fora.
	*/

	int i; 
	for (i=0; i < argc; i++)
	{
		printf("o argumento número %i é %s\n", i, argv[i]);
	}

	/*
		-- Um pouco sobre arrays em C

		Todo o array em C termina com \0.
		Uma string é um array de char consequentemente
		se for passada uma string criada em tempo de execução
		e a mesma não terminar com \0 vai acontecer um overflow de memória.

		No tempo de compilação quando criamos um array usando "" ou {}
		não precisamos explicitamente adicionar o \0 no final
		o gcc cuida disso para você =)


		Tome sempre cuidado com manipulação de strings em tempo de execução.
		
	*/

	/*exemplos maléficos em tempo de execução*/
	/*!!NUNCA IMPLEMENTE ISSO FORA DAQUI!!*/

	#define TAMAMHO_MAXIMO 10
	#define MAIS_QUE_O_TAMANHO_MAXIMO (TAMAMHO_MAXIMO + 30)
	char string_malefica[TAMAMHO_MAXIMO];
	
	for (i=0; i<MAIS_QUE_O_TAMANHO_MAXIMO; i++)
	{
		string_malefica[i] = (char)(33 + i);
	}	

	printf("%s", string_malefica);

# if 0
	/*Isto é um bomba!!*/
	char *cc;
	for (i=0; i< 10000; i++)
	{
		printf("%c", *(cc+i));
	}
#endif

	return 0;

}
