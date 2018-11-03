#include <stdio.h>

const char *months[] = {"LOL", "January", "February", "March",
	"April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main()
{
	int month;
	scanf("%d", &month);
	printf("%s\n", months[month]);
}
