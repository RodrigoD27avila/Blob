#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("/dev/pts/1", O_RDWR);
	write(fd, "Hello", 5);
	close(fd);

}
