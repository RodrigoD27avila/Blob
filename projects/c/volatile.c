#include <stdio.h>

typedef unsigned int special_register;

typedef struct UART UART;
struct UART {
	special_register r0;
	special_register r1;
	special_register r2;
	special_register r3;
	special_register r4;
	special_register r5;
	special_register r6;
	special_register r7;
};

#define UART0 ((UART volatile *)0x0000ffff)

void put(const char *buf, volatile UART *uart)
{
	uart = (UART *)buf;
}

int main()
{
/*	volatile int *i;
	i = ((int volatile *)0x0000ffff);
	printf("%p\n", i);
*/
	
	int *i;
	i = ((int *)0x0000ffff);
	printf("%p\n", i);

	put("Rodrigo", UART0);
	return 0;
}
