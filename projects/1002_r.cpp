#include <cstdio>
#include <cstring>

static int  map[] = {2, 2, 2, 3, 3, 3, 4, 4, 1, 1, 5, 5, 6, 6, 0, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};

size_t number_len;
static char number[101];
static char buffer[51];

static unsigned int table[100][10];

int main()
{
	while (scanf("%s", number) && number[0] != '-') {

		number_len = strlen(number);

		int size;
		scanf("%i", &size);

		unsigned char c;
		int i, j;
		for (i=0; i<size; i++) {
			scanf("%s", buffer);
			printf("%s\n", buffer);
			for (j=0;buffer[j] != 0;j++) {
				c = buffer[j];
				if (table[j][map[c - 'a']] == 0) {
					table[j][map[c - 'a']] = -1;
				}
			}
			table[j-1][map[c - 'a']] = i+1;
		}

		printf("%s\n", number);
		for (i=0; i<100; i++) {
			for (j=0; j<10; j++) {
				printf("%3i", table[i][j]);
			}
			printf("\n");
		}
	}
}
