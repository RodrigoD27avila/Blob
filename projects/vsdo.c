#include <stdio.h>
#include <sys/auxv.h>



int main()
{
	void *vsdo = (uintptr_t) getauxval(AT_SYSINFO_EHDR);
	printf("%p\n", vsdo);
}
