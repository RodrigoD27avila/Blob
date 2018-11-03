#include <sys/reboot.h>

int
main ()
{
	return reboot (RB_AUTOBOOT);
}
