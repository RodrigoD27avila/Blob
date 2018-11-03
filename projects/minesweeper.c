#include <stdio.h>
#include <stdlib.h>

typedef unsigned char cell[2];
static cell table[102][102];

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
			int x = rand() % w + 1;
			int y = rand() % h + 1;

			if (table[y][x][1] != 1) {
				table[y][x][1] = 1;
				break;
			}
		}
	}

	int x, y;
	for (y=0; y<h; y++) {
		for (x=0; x<w; x++) {
			if (table[y+1][x+1][1]) {
			table[y][x][0]     += 1;
			table[y][x+1][0]   += 1;
			table[y][x+2][0]   += 1;
			table[y+1][x+2][0] += 1;
			table[y+2][x+2][0] += 1;
			table[y+2][x+1][0] += 1;
			table[y+2][x][0]   += 1;
			table[y+1][x][0]   += 1;
			}
		}
	}

	int mx, my, game_over = 0, count = 0;
	printf("START GAME!!!\n");

	while (!game_over && printf(">> ") && scanf("%i %i", &mx, &my) && (mx != -1 || my != -1)) {

		if (((w*h) - count) == m) {
			printf("YOU WIN THE GAME!!\n");
			break;
		} else {
			count = 0;
		}

		if (mx > w+1 || my > h+1) {
			printf("try again!!\n");
			continue;
		}

		if (table[my+1][mx+1][1] == 1) {
			game_over = 1;
		} else {
			table[my+1][mx+1][1] = 2;
		}

		for (y=0; y<h; y++) {
			for (x=0; x<w; x++) {
				int ry = y+1;
				int rx = x+1;
				if (game_over && table[ry][rx][1] == 1) {
					if (y == my && x == mx) {
						printf("@");
					} else {
						printf("*");
					}
				} else if (table[ry][rx][1] == 2) {
					printf("%i", table[ry][rx][0]);
					count+=1;
				} else {
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	if (game_over) {
		printf("GAME OVER!!\n");
	}

	return 0;
}

