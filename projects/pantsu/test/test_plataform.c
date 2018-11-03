#include <stdio.h>
#include <core/Pantsu_core.h>

int main()
{
    printf("PANTSU_OS_NAME = %s\n",
        PANTSU_OS_NAME);

    printf("PANTSU_COMPILER_NAME = %s\n",
        PANTSU_COMPILER_NAME);

    printf("PANTSU_ARCHITECTURE_NAME = %s\n",
        PANTSU_ARCHITECTURE_NAME);

    printf("PANTSU_MICROARCHITECTURE_NAME = %s\n",
        PANTSU_MICROARCHITECTURE_NAME);

    printf("PANTSU_MICROARCHITECTURE_CPU_NAME = %s\n",
        PANTSU_MICROARCHITECTURE_CPU_NAME);

    return 0;
}

