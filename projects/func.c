#include <stdio.h>

int sum(int (*s)(int a, int b))
{
	return s(10 , 20);
}

int s(int a, int b)
{
	return a+b;
}

int main()
{
	return sum(s);
}
