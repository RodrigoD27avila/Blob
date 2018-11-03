#include <stdio.h>
#include <unistd.h>
#include <sys/io.h>

#define R 1
#define L 2
#define M 4

#define PORT 0x60

void set_leds(unsigned char led)
{
	outb(0xed, PORT);
	while(inb(PORT + 4) & 2);
	outb(led, PORT);
	while(inb(PORT + 4) & 2);
	usleep(500);
}

int main ()
{
	ioperm(PORT, 5, 1);
	int a = 3;
	while (a) {
		set_leds(L);
		set_leds(M);
		set_leds(R);
		a -= 1;
	}
	ioperm(PORT, 5, 1);
	
	return 0;
}
