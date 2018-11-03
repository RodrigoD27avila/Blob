#include <stdio.h>
#include <time.h>

int main()
{
	time_t rawtime;
	struct tm *timeinfo;
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("current time and dade is %s\n", asctime(timeinfo));
	printf("%s\n", ctime(&rawtime));
	return 0;
}

