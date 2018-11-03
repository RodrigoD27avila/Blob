#include <stdio.h>

typedef void (pfunc_t) (void);

void print_hello_lower()
{
	printf("hello\n");
}

void print_bye_lower()
{
	printf("bye\n");
}

void print_hello_upper()
{
	printf("HELLO\n");
}

void print_bye_upper()
{
	printf("BYE\n");
}

void print_hello_and_bye(pfunc_t *hello, pfunc_t *bye)
{
	hello();
	bye();
}

int main()
{
	print_hello_and_bye(print_hello_lower, print_bye_lower);
	print_hello_and_bye(print_hello_upper, print_bye_upper);

	return 0;
}
