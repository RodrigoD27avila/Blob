#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];
	memset(str, 0, 50);
	printf("Qual é o seu nome?\n");
	fgets(str, 50, stdin);
	printf("Seu nome é %s\n", str);
	
	return 0;
}

