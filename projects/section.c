extern int foobar(void) __attribute__((section ("foobaloo")));

int foobar()
{
	int a = 10;
	int b = 20;
	int c = b;
	b = a;
	a = c;

	return a;
}
