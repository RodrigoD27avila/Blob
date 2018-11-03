#define MAX 4096
unsigned char matrix[MAX][MAX];

int main()
{

	int i, j;
	for (j=0; j<MAX; j++) {
		for (i=0; i<MAX; i++) {
			matrix[i][j] = (i+j) % 256;
		}
	}

	return 0;
}
