#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/input.h>

#define N_EFFECTS 6

#define m_bpl     (sizeof(long) * 8)
#define m_off(x)  (x % m_bpl)
#define m_bit(x)  (1UL << m_off(x))
#define m_long(x) ((x)/m_bpl)

#define test_bit(bit, array) ((array[m_long(bit)] >> m_off(bit)) & 1)

int main(int argc, char **argv)
{
	struct ff_effect effects[N_EFFECTS];
	struct input_event play, stop;
	int fd;

	char device_file_name[64];
	unsigned long features[4];
	int n_effects;
	int i;

	strncpy(device_file_name, "/dev/input/event0", 64);

	for (i=1; i < argc; i++) {
		strncpy(device_file_name, argv[1], 64);
	}

	if ((fd = open(device_file_name, O_RDWR) == -1)) {
		perror("Open device file");
		exit(EXIT_FAILURE);
	}

	printf("Device %s openned.\n", device_file_name);

	if (ioctl(fd, EVIOCGBIT(EV_FF, sizeof(unsigned long) * 4), features) < 0) {
		
		perror("Ioctl query");
		exit(EXIT_FAILURE);
	}

	printf("Axes quiery: ");
	if (test_bit(ABS_X, features)) printf ("Axis X ");
	if (test_bit(ABS_Y, features)) printf ("Axis Y ");
	if (test_bit(ABS_WHEEL, features)) printf ("Axis Wheel ");

	return 0;
}

