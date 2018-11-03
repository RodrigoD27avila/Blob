#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int fd = open("/dev/input/mice", O_RDONLY);
	if (fd <= 0) {
		fprintf(stderr, "unable to open mouse.\n");
		exit(EXIT_FAILURE);
	}

	ssize_t size = 0;
	int wrap = 0;
	unsigned char buff[1];

	while ((size = read(fd, &buff[0], 1) != -1)) {
		printf("%03i ", (int)(buff[0]));
		wrap += 1;
		if (wrap == 20) printf("\n"), wrap = 0;
	}

	close(fd);

	return 0;
}
