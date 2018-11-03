#include <stdio.h>
#include <stdlib.h>

#define ERROR 1
#define INIT_DATA_SIZE 1024

struct objects {
	unsigned int size;
	unsigned int count;
	void *datap;
	
};

struct objects g_objects;

int init_all()
{
	//g_objects = malloc(sizeof(objects));
	//if (!g_objects)
	//	goto end_this;
	
	void *datap = malloc(INIT_DATA_SIZE);
	if (!datap)
		goto end_this;

	g_objects.datap = datap;

	return 0;

end_this:
	return -ERROR;
}

void quit_all()
{
	free(g_objects.datap);
}

void register_object()
{
	unsigned int *objp = (unsigned int *)g_objects.datap;
	objp += g_objects.count;
	*objp = g_objects.count;
	g_objects.count += 1;
}


int main()
{
	if (init_all() < 0)
		exit(EXIT_FAILURE);

	register_object();
	register_object();
	register_object();
	
	unsigned int *objp = (unsigned int *)g_objects.datap;
	printf("%u\n", objp[0]);
	printf("%u\n", objp[1]);
	printf("%u\n", objp[2]);
	
	quit_all();
	return 0;
}
