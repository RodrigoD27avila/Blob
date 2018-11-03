#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
	DIR *d;
	struct dirent *dir;

	d = opendir(".");
	if (d == NULL) {
		perror("Unable to open directory.");
		exit(EXIT_FAILURE);
	}

	while ((dir = readdir(d)) != NULL) {
		printf("%s\n", dir->d_name);
	}

	printf("%lu\n", sizeof(*dir));
	printf("%p\n", &dir->d_name);
	printf("%p\n", dir);
	

	closedir(d);

	return 0;
}
