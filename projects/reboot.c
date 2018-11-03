#include <unistd.h>
#include <linux/reboot.h>

int main()
{
    reboot(LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, 0, NULL);
    return 0;
}
