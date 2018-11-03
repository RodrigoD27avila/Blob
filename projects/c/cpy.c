#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *buf = (char*)malloc(50);
	memset(buf, 0, 50);

	int n = 1000;
	memcpy(buf, &n, sizeof(int));

	int i;	
	for (i=0; i<50; i++) {
		char c =  *(buf+i);
		printf("%c\n", c);
	}

	free(buf);
	return 0;
}
