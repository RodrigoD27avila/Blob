#include <stdio.h>
#include <stdlib.h>

struct pessoa {
	char nome[100];
	int ano_nascimento;
	char cpf[11];
};


void preenche_pessoa(struct pessoa *pessoa)
{
	scanf("%s", &pessoa->nome);
	scanf("%d", &pessoa->ano_nascimento);
	scanf("%s", &pessoa->cpf);
}

void printa_pessoa(struct pessoa *pessoa)
{
	printf("nome=%s, ano=%i, cpf=%s\n", pessoa->nome,
		pessoa->ano_nascimento, pessoa->cpf);
}

int main()
{
	struct pessoa *pessoa = malloc(sizeof(struct pessoa));
	preenche_pessoa(pessoa);
	printa_pessoa(pessoa);
	free(pessoa);
}
