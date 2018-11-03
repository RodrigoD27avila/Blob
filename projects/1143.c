#include <stdio.h>

const int comp[12][4] = {
	{0, 1, 2, 3}, {0, 3, 1, 2}, {0, 2, 3, 1},
	{1, 3, 2, 0}, {1, 0, 3, 2}, {1, 2, 0, 3},
	{2, 1, 3, 0}, {2, 0, 1, 3}, {2, 3, 0, 1},
	{3, 2, 1, 0}, {3, 0, 2, 1}, {3, 1, 0, 2},
};

int main()
{
	const char c1[5];
	const char c2[5];

	scanf("%s", &c1[0]);
	scanf("%s", &c2[0]);

	int i, j;
	for (i=0; i<12; i++) {
		int e = 0;
		for (j=0; j<4; j++) {
			if (c1[comp[i][j]] == c2[j]) {
				e++;
			}
		}

		if (e == 4) {
			printf("equal\n");
			return 0;
		}
	}

	printf("different\n");
	return 0;
}

