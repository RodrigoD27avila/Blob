#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
	struct dirent *dir;
	printf("%s\n", dir->d_name);

	return 0;
}
