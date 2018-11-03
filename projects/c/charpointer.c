#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createnewbuffer(char **buffer)
{
	char *newbuffer = malloc(128);
	memset(newbuffer, 0, 128);
	memcpy(newbuffer, "Rodrigo", 7);

	*buffer = newbuffer;
}

int main()
{
	char *buffer = NULL;
	createnewbuffer(&buffer);
	printf("%s\n", buffer);
	free(buffer);
	return 0;	
}
