#include <stdio.h>
#include <string.h>

int main()
{
	char str1[1] = "\0";
	char *str2 = "Rodrigo";

	strncat(str1, str2, 7);
	printf("%s\n", str1); 
	return 0;
}
