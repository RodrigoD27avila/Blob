#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <asm/types.h>

#define DEFAULT_FB_DEVICE "/dev/fb0"

int open_fb(const char *fbd)
{
	int fd;

	const char *device = fbd;
	if (device == NULL) {
		device = DEFAULT_FB_DEVICE;
	}

	if ((fd = open(device, O_RDWR)) < 0) {
		perror(device);
		exit(EXIT_FAILURE);
	}

	return fd;
}

void close_fb(int fd)
{
	close(fd);
}

void get_var_screeninfo(int fd, struct fb_var_screeninfo *var)
{
	if (ioctl(fd, FBIOGET_VSCREENINFO, var) < 0) {
		perror("ioctl => FBIOGET_VSCREENINFO");
		exit(EXIT_FAILURE);
	}
}

void get_fix_screeninfo(int fd, struct fb_fix_screeninfo *var)
{
	if (ioctl(fd, FBIOGET_FSCREENINFO, var) < 0) {
		perror("ioctl => FBIOGET_FSCREENINFO");
		exit(EXIT_FAILURE);
	}
}

void display()
{
	struct fb_var_screeninfo var;
	struct fb_fix_screeninfo fix;

	// open frame buffer
	int fd = open_fb(NULL);

	get_var_screeninfo(fd, &var);
	get_fix_screeninfo(fd, &fix);

	unsigned long x_stride = (fix.line_lenght * 8) / var.bits_per_pixel;


	// correct panning
	if (x_pan > x_size - x_stride) x_pan = 0;	
	if (y_pan > y_size - var.yres) y_pan = 0;	
	
	// correct panning
	if (x_offs > x_size - x_stride) x_offs = 0;	
	if (y_offs > y_size - var.yres) y_offs = 0;

	// close frame buffer
	close_fb(fd);

	// convert buffer
	// blit buffer
}

int main()
{
	display_info();
	return 0;
}
