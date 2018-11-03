#include <linux/slab.h>

int main()
{
	void *p = kmalloc(sizeof(int), GFP_ATOMIC);
	kfree(p);
	return 0;
}
