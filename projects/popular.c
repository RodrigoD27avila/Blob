#include <stdio.h>

static int alunos[100];

int main()
{
	int  qtd;
	char str[2];
	while (scanf("%i", &qtd) && qtd != 0) {
		int i, j;
		for (i=0; i<qtd; i++) {
			for (j=0; j<qtd; j++) {
				scanf("%s", str);
				if (str[0] == '1') {
					alunos[j]+=1;

				}
			}
		}

		int maior = 0;
		for (j=0; j<100; j++) {
			if (alunos[j] > maior) {
				maior = alunos[j];
			}
				alunos[j] = 0;
		}
		printf("%i\n", maior);
	}

	return 0;
}

