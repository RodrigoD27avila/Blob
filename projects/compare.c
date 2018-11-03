#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 50

int main()
{
	// define user and password
	static char user[MAX_CHARACTERS];
	static char pass[MAX_CHARACTERS];

	while (strcmp(user, pass) == 0) {

		// zero user and password
		memset(user, 0, MAX_CHARACTERS);
		memset(pass, 0, MAX_CHARACTERS);

		printf("Digite o usuario: ");
		fgets(user, MAX_CHARACTERS, stdin);
		printf("Digite a senha: ");
		fgets(pass, MAX_CHARACTERS, stdin);

		if (strcmp(user, pass) == 0) {
			fprintf(stderr, "Usuario igual a senha."
				" digite novamente.\n");
		}

		printf("programa finalizado!\n");
	}
}
