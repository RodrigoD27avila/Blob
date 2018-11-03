#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/cdrom.h>

#define CDDEVICE "/dev/sr0"

static int eject_cdrom(int cdrom)
{
	ioctl(cdrom, CDROM_SET_OPTIONS, CDO_AUTO_EJECT);
#if   defined (CDROMEJECT)
	return ioctl(cdrom, CDROMEJECT, 0) >= 0;
#elif defined (CDIOCEJECT)
	return ioctl(cdrom, CDIOCEJECT, 0) >= 0;
#endif
	return 0;
}

int main()
{
	int cdrom;

	if ((cdrom = open(CDDEVICE, O_RDONLY | O_NONBLOCK) < 0)) {
		perror("open");
		exit(1);
	}

	if (eject_cdrom(cdrom)  < 0) {
		perror("eject");
		exit(1);
	}

	close(cdrom);

	return 0;
}

