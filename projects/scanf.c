#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buffer[50];
	memset(buffer, 0, 50);

	printf("Entre com os números:\n");
	scanf("%50s", buffer);
	printf("%s\n", buffer);	

	return 0;
}
