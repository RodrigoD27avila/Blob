#include <dos.h>

int main()
{
	union REGS in = {0};
	in.h.ah = 0;
	int86(0x21, &in, &in);
	
	return 0;
}
