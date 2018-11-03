#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concate(char *str1, char *str2)
{
	int len1, len2;
	len1 = strlen(str1);
	len2 = strlen(str2);

	char *newstr = malloc(len1+len2+1);
	if (newstr == NULL) {
		return NULL;
	}

	memset(newstr     , 0   , len1+len2+1);
	memcpy(newstr     , str1, len1);
	memcpy(newstr+len1, str2, len2);
	return newstr;
}

int main()
{
	char *newstr = concate("####Rodrigo####", " ______D'avila______");
	printf("%lu, %s\n", strlen(newstr), newstr);	
	free(newstr);

	return 0;
}
