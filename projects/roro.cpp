#include <cstdio>
#include <cstring>

static char map[] = {'2', '2', '2', '3', '3', '3', '4', '4', '1', '1', '5', '5', '6',
                     '6', '0', '7', '0', '7', '7', '8', '8', '8', '9', '9', '9', '0'};

static char number[100];

static char dict[50000][50];
static char points[50000][100];


void decode(int index)
{
	int i, j;
	for (i=0; i<100 && number[i] != 0; i++) {
		if (number[i] == map[dict[index][0] - 'a']) {
			for (j=0; j<100 && dict[index][j] != 0 && number[i+j] != 0; j++) {
				if (number[i+j] == map[dict[index][j] - 'a'] && dict[index][j+1] == 0) {
					points[index][i] = j;
				}
			}
		}
	}

}

int main()
{
	while (scanf("%s", number) && number[0] != '-') {

		memset(dict, 0, 50000 * 50);
		memset(points, 0, 50000 * 100);

		int size;
		scanf("%i", &size);

		int i, j;
		for (i=0; i<size; i++) {
			scanf("%s", (char *)&dict[i]);
			decode(i);
			for (j=0; j<100; j++) {
				printf("%x", points[i][j]);
			}
			printf("\n");
		}
	}
}
