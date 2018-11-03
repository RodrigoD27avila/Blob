#include <stdio.h>
#include <core/Pantsu_core.h>

int main()
{
    P_SIGNEDINT8_T  i8  = 0;
    P_SIGNEDINT16_T i16 = 0;
    P_SIGNEDINT32_T i32 = 0;
    P_SIGNEDINT64_T i64 = 0;

    #if (PANTSU_PLATAFORM_64BIT)
    printf ("%lu\n", sizeof(i8) *8);
    printf ("%lu\n", sizeof(i16)*8);
    printf ("%lu\n", sizeof(i32)*8);
    printf ("%lu\n", sizeof(i64)*8);
    #else
    printf ("%u\n", sizeof(i8) *8);
    printf ("%u\n", sizeof(i16)*8);
    printf ("%u\n", sizeof(i32)*8);
    printf ("%u\n", sizeof(i64)*8);
    #endif
    return 0;
}
