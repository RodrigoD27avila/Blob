#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void to_num(char *buff, int len)
{
	int i;
	for (i=0; i<len; i++) {
		buff[i] -= '0';
	}
}

void to_char(char *buff, int len)
{
	int i;
	for (i=0; i<len; i++) {
		buff[i] += '0';
	}
}


void sort(char *buff, int len) {

	int occur[256];
	memset(occur, 0, sizeof(int) * 256);

	int i, j;
	for (i=0; i < len; i++) {
		for (j=0; j<buff[i]+1; j++) {
			occur[j]++;
		}
	}

	for (i=0; occur[0] != 0; i++) {
		int c=0, k;
		for (j=0, k=occur[0]; k == occur[j]; j++) {
			c++; occur[j] -= 1;
		}
		buff[i] = abs(buff[i] - (c-1));
	}
}

int main()
{
	char buff[] = "199000000";
	int len = strlen(buff);
	int i;
	while (1) {
//	for (i=0; i<50; i++) {
		printf("%s\n", buff);
		to_num (buff  , len);
		sort   (buff  , len);
		to_char(buff  , len);
//		sleep(1);
	}

	return 0;
}
