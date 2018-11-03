#include <stdio.h>

const char *name = "Rodrigo";


const char *getname()
{
	return name;
}

int main()
{
	const char *myname = getname();
	printf(myname);
	return 0;
}
