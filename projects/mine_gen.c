#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned char table[100][100];

int main(int argc, char **argv)
{
	if (argc <=3 ) {
		fprintf(stderr, "USAGE: %s width height mines\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int w = atoi(argv[1]);
	int h = atoi(argv[2]);
	int m = atoi(argv[3]);

	if (w > 100 || h > 100 || m > (w*h)) {
		fprintf(stderr, "Input error.\n");
		exit(EXIT_FAILURE);
	}

	int i, j;
	srand(time(NULL));
	for (i=0; i<m; i++) {
		for (;;) {
			int x = rand() % w;
			int y = rand() % h;

			if (table[y][x] != 1) {
				table[y][x] = 1;
				break;
			}
		}
	}

	printf("%i %i\n", h, w);
	for (i=0; i<h; i++) {
		for (j=0; j<w; j++) {
			if (table[i][j]) {
				printf("*");
			} else {
				printf(".");
			}
		}
		printf("\n");
	}
}
