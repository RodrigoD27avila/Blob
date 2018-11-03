#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HIGH(c) ((c & 0xf0) >> 4)
#define  LOW(c)  (c & 0x0f)

int main()
{
	int buff[8];
	memset(buff, '\0', 8 * sizeof(int));

	char *byte = (char *)buff;
	*(byte+1) = '+'; 
	*(byte+2) = 'R'; 

	printf("%i\n", *(byte));
	printf("%c\n", *(byte+1));
	printf("%c\n", *(byte+2));

	printf("%i\n", 1 << 0);
	unsigned short int *shortbuff = (unsigned short int *)buff;
	*shortbuff = (1<<15);// (unsigned short int)(1<<15);
	printf("%c\n", *(byte));
	printf("%c\n", *(byte+1));
	printf("%c\n", *(byte+2));
	return 0;
}
