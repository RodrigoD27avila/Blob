#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <unistd.h>

#define FB "/dev/fb0"

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};
	
int main()
{
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	unsigned char            *pixels;

	int    screen_size;

	int fd;

	// open device
	if ((fd = open(FB, O_RDWR)) < 0) {
		perror("Unable to open device");
		exit(EXIT_FAILURE);
	}

	// fixed screen properties
	if (ioctl(fd, FBIOGET_FSCREENINFO, &finfo) < 0) {
		perror("error: FBIOGET_FSCREENINFO");
		exit(EXIT_FAILURE);
	}

	// virtual screen properties
	if (ioctl(fd, FBIOGET_VSCREENINFO, &vinfo) < 0) {
		perror("error: FBIOGET_VSCREENINFO");
		exit(EXIT_FAILURE);
	}

	// get screen size in bytes
	screen_size = vinfo.xres * vinfo.yres * (vinfo.bits_per_pixel / 8);

	// map screen
	pixels = mmap(0, screen_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (pixels == (unsigned char *)-1) {
		perror("error: mmap");
		exit(EXIT_FAILURE);
	}

	printf("device info   : %s - %s\n", FB, finfo.id);
	printf("witdh         : %d\n", vinfo.xres);
	printf("height        : %d\n", vinfo.yres);
	printf("bits per pixel: %d\n", vinfo.bits_per_pixel);

	struct Color color = {255, 000, 255, 255};

	int x, y;
	for (y=100; y<300; y++) {
		for (x=100; x<300; x++) {
			unsigned int coord = ((x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8))
				+ (y+vinfo.yoffset) * finfo.line_length;
			memcpy(pixels+coord, &color,  sizeof(struct Color));
		}
	}

	munmap(pixels, screen_size);
	close(fd);

	return 0;
}
