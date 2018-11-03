#include <unistd.h>

#define BUF 100

int main(int argc, char **argv)
{
	char string[BUF] = "Rodrigo D'avila\n";
	
	if (write(1, string, BUF) < 0) {
		_exit(1);
	}

	return 0;
}
