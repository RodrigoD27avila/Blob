#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
	-- O que são macros em C

	Explicação simples ;)
	O macro é uma palavra que é definida pela diretiva #define e
	na hora de compilar ela é substituída pela expressão seguida a ela.
	Ex:

	#define EXIT_SUCCESS 0
	agora todo o lugar onde aparecer EXIT_SUCCESS vai ser substituído por 0

	#define MAX_ENEMIES 100
	#define MAX_SHOTS   500
	#define MAX_OBJECTS MAX_ENEMIES + MAX_SHOTS

	agora todo o lugar onde aparecer MAX_ENEMIES vai ser substituído por 100
	e onde aparecer MAX_SHOTS vai ser substituido por 500

	consequentemente onde aparecer MAX_OBJECTS vai ser substituído por 
	100 + 500
*/


/*quando forem testar tentem modificar os valore abaixo*/
#define MAX_ENEMIES 100
#define MAX_SHOTS   500
#define MAX_OBJECTS MAX_ENEMIES + MAX_SHOTS

/*
	aqui eu sei que MAX_OBJECTS é MAX_ENEMIES + MAX_SHOTS
	quando se declara uma variável fora de um método 
*/

int g_myobjects[MAX_OBJECTS];

void init_enemies(void);
void init_shots(void);
void init_objects(void);

/*
	-- Mais sobre macros

	Outra maneira de definir macros é passando parâmetros.
	Ex:

	#define SUM(a, b, c, d) a + b + c + d
	#define MAX(a, b) ((a > b) ? a : b)
	
*/
	

#define SUM(a, b) a + b
#define SUM4(a, b, c , d) a + b + c + d

#define MAX(a, b) ((a > b) ? a : b)
#define MAX4(a, b, c, d) MAX(MAX(a,b), MAX(c,d))


/*
	-- Concatenando strings

	#define CONCAT_NSPACE(str1, str2) #str1 #str2
	#define	CONCAT_WSPACE(str1, str2) #str1 " " #str2
	
*/


/*
	você pode quebrar linhas quando define um macro
	mas lembre-se de não deixar nenhum caracter de espaço
	ou qualquer outro que não seja a quebra de linha
	depois do \
*/	
#define CONCAT_NSPACE(str1, str2) \
	#str1 #str2

#define	CONCAT_WSPACE(str1, str2) \
	#str1 " " #str2

/*

	-- Concatenando símbolos

	#define call_LNFunction(name) \
		this_is_a_function_with_a_very_very_long_name_ ## 1

*/
	
/*
	Macros podem ter seu nome escrito só com letras minusculas
	ou misturando ambas maiúsculas e minusculas.
*/
#define call_LNFunction(name) \
	this_is_a_function_with_a_very_very_long_name_ ## name

/*
	-- Curiosidades e outras aplicações

	Quando se define um macro e não se escreve nada depois, o
	macro vai ser substituído por nada.
	Ex:

	#define __NOTHING
	
	Uma aplicação não muito comum é definir esses macros para
	deixar o código mais descritivo.

	Ex:

	#define __in
	#define __out
	#define __no_raise 

*/

#define __NOTHING

#define __in  /* valor não vai ser modificado*/
#define __out /* valor vai ser modificado*/
#define __no_raise  /* a função não tem exceções*/

void my_descriptive_function( __in  int, __in  int, __out int*) __no_raise;


/*
	-- Usando o gcc

	Quando se passa o parâmetro -E o gcc mostra
	o output de pré-processamento é legal para ver
	como ele substituiu os macros.

	Ex:
		gcc file.c -E

	Outra opção é passa o parâmetro -dM, o gcc
	vai mostrar todos os macros definidos.

	Ex:
		gcc file.c -dM -E
*/

#endif /*MACROS_H_INCLUDED*/ 
