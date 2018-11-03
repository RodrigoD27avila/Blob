#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char **argv)
{
	int fd, value, *ptr;
	
	fd = shm_open("/sharedmem", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		perror("sh_open");
		exit(EXIT_FAILURE);
	}

	if (ftruncate(fd, sizeof(value)) == -1) {
		perror("ftruncate");
		exit(EXIT_FAILURE);
	}

	ptr = mmap(NULL, sizeof(value), PROT_READ | PROT_WRITE,
		MAP_SHARED, fd, 0);
	if (ptr == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		value = random() % 1000;
		(*ptr) = value;
		printf("Wrote value %i\n", value);
		sleep(1);

		value = (*ptr);
		printf("Read value %i\n", value);
		sleep(1);
	}

	return 0;	
}
