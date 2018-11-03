#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *buff = malloc(1024 * 1024 * 1024 * sizeof(char));
	sleep(30);
	free(buff);
	return 0;
}

