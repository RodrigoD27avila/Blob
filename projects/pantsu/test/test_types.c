#include <stdio.h>

#include <core/Pantsu_core.h>

int main()
{
    printf("PChar  = %d\n", sizeof(PChar)  * 8);
    printf("PShort = %d\n", sizeof(PShort) * 8);
    printf("PInt   = %d\n", sizeof(PInt)   * 8);
    printf("PLong  = %d\n", sizeof(PLong)  * 8);
    printf("\nPMagic = %d\n", sizeof(PMagic)  * 8);
}

