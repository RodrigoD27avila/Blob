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

#ifdef __cplusplus
	#define EXTC extern "C" 
#else
	#define EXTC
#endif

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};
	
static struct fb_var_screeninfo vinfo;
static struct fb_fix_screeninfo finfo;
static unsigned char            *pixels;

inline void put_pixel(unsigned int x, unsigned int y, struct Color *color);

EXTC void bresenham(int x1, int y1, int x2, int y2, struct Color *color)
{
	int slope = 1;
	int dx, dy, INCE, INCNE, d, x ,y;

	// inverte se x1 > x2
	if (x1 > x2) {
		bresenham(x2, y2, x1, y1, color);
		return;
	}

	dx = x2 - x1;
	dy = y2 - y1;

	if (dy < 0) {
		slope = -1;
		dy    = -dy; 
	}

	// constante de bresenham
	INCE  = (2 * dy);
	INCNE = (2 * dy) - (2 * dx);
	d     = (2 * dy) - dx;
	y     = y1;

	for (x = x1; x <= x2; x++) {
		put_pixel(x, y, color);
		
		if (d <= 0) {
			d += INCE;
		}
		else {
			d += INCNE;
			y += slope;
		}
	} 
}


int main()
{
	int screen_size;
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
	pixels = (unsigned char *)mmap(0, screen_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (pixels == (unsigned char *)-1) {
		perror("error: mmap");
		exit(EXIT_FAILURE);
	}

	printf("device info   : %s - %s\n", FB, finfo.id);
	printf("witdh         : %d\n", vinfo.xres);
	printf("height        : %d\n", vinfo.yres);
	printf("bits per pixel: %d\n", vinfo.bits_per_pixel);

	struct Color black = {000, 255, 255, 000};
	struct Color color = {255, 000, 255, 000};

	int x, y;
	for (x=0; x<800; x++) {
		for (y=0; y<600; y++) {
			put_pixel(x, y, &black);
		}
	}


	for (y=0; y<600; y+=25) {
		bresenham(0, 0, 800, y, &color);
	}

	munmap(pixels, screen_size);
	close(fd);

	return 0;
}

inline void put_pixel(unsigned int x, unsigned int y, struct Color *color)
{
	unsigned int coord = ((x + vinfo.xoffset) * (vinfo.bits_per_pixel / 8))
		+ (y+vinfo.yoffset) * finfo.line_length;
	memcpy(pixels+coord, color,  sizeof(struct Color));
}
