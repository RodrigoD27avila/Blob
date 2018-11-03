#include <stdlib.h>

int main();

struct 
{
	void *my_data;

}g_info;

void free_and_quit(void)
{
//	free(g_info.my_data);
	main();
}

int main()
{
	atexit(free_and_quit);

//	g_info.my_data = malloc(8);
//	free(g_info.my_data);

	return 0;
}
