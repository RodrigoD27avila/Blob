#include <stdio.h>

int main()
{
	FILE *file = fopen("/home/rodrigo/dragon_ball-10.mkv", "rb");
	fseek(file, 1024, SEEK_SET);
	fseek(file, 80586691, SEEK_SET);
	fclose(file);
	return 0;
}
