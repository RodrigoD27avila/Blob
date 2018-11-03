#include <stdio.h>

void foo() 
{
	int i;
	i+=67;
	printf("%p\n", &i);
}

int main()
{
	foo();	
	foo();
	return 0;	
}
