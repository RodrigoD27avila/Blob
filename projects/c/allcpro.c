#include <stdio.h>

int
main() {

	/*initialize a variables*/
	char s[16];
	char c;
	int i = 0, j;

	while ((c=getchar()) != '\n') {

		for (j = 1; j < i; j++) {
			s[j] = ' ';
		}

		i++;
		printf("%s\n", s);
	}


	return 0;
}
