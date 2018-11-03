#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARESTAS 676
#define MAX_LETTERS 26
#define INF 0x7fffffff

static int G[MAX_ARESTAS];
static char buff[512];

int main()
{
	int n, U, V, i, j, k;
	fgets(buff, 64, stdin);
	n=atoi(buff);

	fgets(buff, 64, stdin);
	U=buff[0]-'A'; V=buff[2]-'A';

	for (i=0; i<n; i++) {
		fgets(buff, 511, stdin);
		for (j=0, k=0; j<n; j++) {
			G[(i*n)+j] = (buff[k] == 'I') ? INF : atoi(&buff[k]);
			for (;buff[k] != '\0' && buff[k] != ' '; k++); k+=1;
		}
	}

	printf("U=%i, V=%i\n", U, V);
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			printf("%10i ", G[(n*i)+j]);
		}
		printf("\n");
	}
	

	
}
