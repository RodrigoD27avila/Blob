#include <stdio.h>
#include <string.h>

typedef unsigned char cell[2];

static cell table[102][102];
static char row[101];

int main()
{
	int w, h, f=1;
	while (scanf("%i %i", &h, &w) && (w!=0 && h!=0)) {

		int x, y;
		for (y=0; y<h; y++) {
			scanf("%s", row);
			for (x=0; row[x]!=0; x++) {
				if (row[x] == '*') {

				table[y][x][0]     += 1;
				table[y][x+1][0]   += 1;
				table[y][x+2][0]   += 1;
				table[y+1][x+2][0] += 1;
				table[y+2][x+2][0] += 1;
				table[y+2][x+1][0] += 1;
				table[y+2][x][0]   += 1;
				table[y+1][x][0]   += 1;

				table[y+1][x+1][1] = 1;
				}
			}
		}

		printf("Field #%i:\n", f++);
		for (y=0; y<h; y++) {
			for (x=0; x<w; x++) {

				int ry = y+1;
				int rx = x+1;

				if (table[ry][rx][1]) {
					printf("*");
				} else {
					printf("%i", table[ry][rx][0]);
				}
			}
			printf("\n");
		}
		printf("\n");
		memset(table, 0, sizeof(cell) * 102 * 102);

	}
}

