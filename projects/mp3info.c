#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

typedef struct {
	int fd;
	unsigned long file_size;
} MP3FILE;

MP3FILE *mp3fileNew(const char *path)
{
	int fd = open(path, O_RDONLY);
	if (fd < 0) {
		perror(path);
		goto end_with_error;
	}



	MP3FILE *mp3 = malloc(sizeof(MP3FILE));
	return mp3;

end_with_error:
	return NULL;
}


int main()
{

}

