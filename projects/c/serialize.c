#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a,b,c,d,e,f,g,h,i,j;
} foo;

int main()
{
	foo f;// = malloc(sizeof(foo));
	f.a = 10;
	f.b = 11;
	f.c = 12;
	f.d = 13;
	f.e = 14;
	f.f = 15;
	f.g = 16;
	f.h = 17;
	f.i = 18;
	f.j = 19;

	FILE *file = fopen("serialize.dump", "wb+");
	fwrite((char *)&f, 1, sizeof(foo), file);

	fflush(file);
	fclose(file);
//	free(f);
	
	return 0;
}
