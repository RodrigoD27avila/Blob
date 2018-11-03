#include <stdio.h>

int main()
{
	const char *a = "vertebradoavecarnivoro";
	const char *b = "vertebradoaveonivoro";
	const char *c = "vertebradomamiferoonivoro";
	const char *d = "vertebradomamiferoherbivoro";
	const char *e = "invertebradoinsetohematofago";
	const char *f = "invertebradoinsetoherbivoro";
	const char *g = "invertebradoanelideohematofago";
	const char *h = "invertebradoanelideoonivoro";

	const char *names[] = {a, b, c, d, e, f, g, h};


	int i, j, sum ;
	for (i=0; i<8; i++) {
		sum = 0;
		for (j=0; names[i][j] != 0; j++) {
			sum += (int)names[i][j];
		}

		printf("%i %s\n", sum, names[i]);
	}
}
