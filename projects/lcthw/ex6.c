#include <stdio.h>

int main()
{
	int    distance    = 100;
	float  power       = 2.345f;
	double super_power = 56789.4532;
	
	char initial     = 'A';
	char firstname[] = "Zed";
	char last_name[] = "Shaw";

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %x.\n", initial);
	printf("I have a first name %s.\n", firstname);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c %s.\n", firstname,
		 initial, last_name);

	return 0;
}
