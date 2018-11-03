#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

static char buff[512];

int main()
{
	int fd;
	fd = open("/home/rodrigo/aaa", O_RDONLY);
	if (fd < 0) {
		perror("aaa");
	}

	ssize_t r = read(fd, buff, 512);
	if (r < 0) {
		perror("read");
	}
	printf(">>>(%li) %s\n", r, buff);

	close(fd);
}
