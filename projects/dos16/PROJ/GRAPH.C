#include <dos.h>

#define VGA256 0x13
#define TEXT   0x03

#define SCREEN_WIDTH  (unsigned int)320
#define SCREEN_HEIGHT (unsigned int)200

unsigned char *VGA = (unsigned char *)0xa0000;

void set_video_mode(int mode)
{
	union REGS in, out;
	in.h.ah = 0;
	in.h.al = (unsigned char)mode;

	int86(0x10, &in, &out);
}

void put_pixel(int x, int y, unsigned char color)
{
	VGA[y*SCREEN_WIDTH+x] = color;
}


int main()
{
	set_video_mode(VGA256);
	int i;
	for (i=0; i< 100; i++) {
		put_pixel(i, 0, 0xe);
	}
	return 0;
}

