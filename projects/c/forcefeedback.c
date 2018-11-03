#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <linux/input.h>

#define BITS_PER_LONG (sizeof(long) * 8)
#define OFF(x)  ((x)%BITS_PER_LONG)
#define BIT(x)  (1UL<<OFF(x))
#define LONG(x) ((x)/BITS_PER_LONG)
#define test_bit(bit, array)    ((array[LONG(bit)] >> OFF(bit)) & 1)

#define N_EFFECTS 6

char *effect_names[] = {
	"Sine Vibration",
	"Constant Force",
	"Spring Condition",
	"Damping Condition",
	"Strong Rumble",
	"Weak Rumble",
};

int main(int argc, char **argv)
{
	struct ff_effect effects[N_EFFECTS];
	struct input_event play, stro;
	int fd, n_effects;
	char device_file_name[64];
	unsigned long features[4];
	
	if (argc <= 1) {
		printf("USAGE: %s /dev/input/eventXX\n", argv[0]);
		printf("Test the force feedback driver.\n");
		exit(EXIT_FAILURE);
	}

	strncpy(device_file_name, argv[1], 64);
	
	printf("Force feedback test program.\n");
	printf("HOLD FIRMLY YOUR WHEEL OR JOYSTICK TO PREVENT DAMAGES\n\n");

	fd = open(device_file_name, O_RDWR);
	if (fd == -1) {
		perror("Open device file");
		exit(EXIT_FAILURE);
	}
	printf("Device %s opened\n", device_file_name);

	int size = sizeof(unsigned int) * 4;
	int ret  = ioctl(fd, EVIOCGBIT(EV_FF, size), features);
	if (ret == -1) {
		perror("Ioctl query");
		exit(EXIT_FAILURE);
	}

	printf("\nAxes query: ");
	if (test_bit(ABS_X, features)) printf("Axes X ");
	if (test_bit(ABS_Y, features)) printf("Axes Y ");
	if (test_bit(ABS_WHEEL, features)) printf("Wheel");
	if (test_bit(ABS_Z, features)) printf("Z ");
	if (test_bit(ABS_RX, features)) printf("RX ");
	if (test_bit(ABS_RY, features)) printf("RY ");
	if (test_bit(ABS_RZ, features)) printf("RZ ");
	

	printf("\nEffents query: ");
	if (test_bit(FF_CONSTANT, features)) printf("Constant ");
	if (test_bit(FF_PERIODIC, features)) printf("Periodic ");
	if (test_bit(FF_SPRING, features))   printf("Spring ");
	if (test_bit(FF_FRICTION, features))   printf("Friction ");
	if (test_bit(FF_RUMBLE, features))   printf("Rumble ");
	if (test_bit(FF_SQUARE, features))   printf("Square ");

	printf("\nNumber of simultaneous effects: ");
	if (ioctl(fd, EVIOCGEFFECTS, &n_effects) == -1) {
		perror("Ioctl number of effects");
	}

	printf("%d\n", n_effects);

	return 0;
}
