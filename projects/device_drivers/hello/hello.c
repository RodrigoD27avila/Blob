#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>

static void *p;

static int __init hello_init(void)
{
	printk("Hello module initialized.\n");
	p = kmalloc(4, GFP_ATOMIC);
	return 0;
}

static void __exit hello_exit(void)
{
	kfree(p);
	printk("Hello module, Good bye =].\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rodrigo D\'avila");
