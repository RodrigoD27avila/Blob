#include <stdio.h>
#include <stdlib.h>

int main()
{

	char str[4];
	int qtd, num, inst = 1;
	while (scanf("%s", &str) != EOF) {
		qtd = atoi(str);
		int i, soma = 0, indice = -100;
		for (i=0; i<qtd; i++) {
			scanf("%i", &num);
			soma += num;
			if (indice < 0 && soma == qtd-1) {
				indice = num;
			}
		}

		if (indice > -100) {
			printf("Instancia %i\n%i\n", inst, indice);
		} else {
			printf("nao achei\n");
		}

		inst += 1;
	}
}
