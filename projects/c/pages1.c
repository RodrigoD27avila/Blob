#define MAX 4096
unsigned char matrix[MAX][MAX];

int main()
{

	int i, j;
	for (i=0; i<MAX; i++) {
		for (j=0; j<MAX; j++) {
			matrix[i][j] = (i+j) % 256;
		}
	}

	return 0;
}
