#include <stdio.h>
#include <stdlib.h>

#define inline_vtoi(i) *((int *)i)
inline int vtoi (void *p) { return *((int *)p); }

#define inline_vtof(i) *((float *)i)
inline float vtof (void *p) { return *((float *)p); }

#define inline_vtoc(i) *((char *)i)
inline char vtoc (void *p) { return *((char *)p); }

#define inlibe_vtos(i) (char *)i
inline char* vtos (void *p) { return (char *)p; }

int
main (int argc, char **argv)
{	
	void *args[4];
	
	int a = 99;
	float b = 20;
	char c = 'R';
	char s[] = "10000";

	args[0] = &a;
	args[1] = &b;
	args[2] = &c;
	args[3] = &s;

	printf ("%i\n", vtoi (args[0]));
	printf ("%f\n", vtof (args[1]));
	printf ("%c\n", vtoc (args[2]));
	printf ("%s\n", vtos (args[3]));
	return 0;
}
