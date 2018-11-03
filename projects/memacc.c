unsigned char buffer[4096][4096];

int main()
{
	int i, j;

	for (j=0;j<4096;j++) {
		for (i=0;i<4096;i++) {
			buffer[i][j] = (i+j) % 256;
		}
	}

}
