#include <stdio.h>

int main (int argc, char *argv[]) {
	FILE *file;
	file = fopen ("/home/rdapache/projects/c//nacho", "rb");
	while (file != EOF) {
		printf ("%x | ", getc(file));
	}
	return fclose (file);

}
