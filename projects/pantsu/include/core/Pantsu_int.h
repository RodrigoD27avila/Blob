#ifndef PANTSU_INT_INCLUDED
#define PANTSU_INT_INCLUDED

#define P_SIGNEDINT8_T  signed char
#define P_SIGNEDINT16_T signed short
#define P_SIGNEDINT32_T signed int

#define P_UNSIGNEDINT8_T  unsigned char
#define P_UNSIGNEDINT16_T unsigned short
#define P_UNSIGNEDINT32_T unsigned int


#if !defined (PANTSU_COMPILER_UNKNOWN) \
        && !defined (PANTSU_ARCHITECTURE_UNKNOWN)

#if defined (PANTSU_STANDARD_C_99)

    #define P_SIGNEDINT64_T signed long long
    #define P_UNSIGNEDINT64_T unsigned long long

#else

    #if defined (PANTSU_COMPILER_GCC)

        /* __extension__ */

        #define P_SIGNEDINT64_T  signed long long
        #define P_UNSIGNEDINT64_T unsigned long long
    
    #elif defined (PANTSU_COMPILER_MSC) || defined (PANTSU_COMPILER_WATCOM)

        /*
         * Open Watcom
         * Restrictions:
         * An __int64 expression cannot be used in a switch statement.
         * More than 32 bits in a 64-bit bitfield is not supported. 
         */

        /* =/ */
        #undef P_SIGNEDINT8_T
        #undef P_SIGNEDINT16_T
        #undef P_SIGNEDINT32_T
        #undef P_UNSIGNEDINT8_T
        #undef P_UNSIGNEDINT16_T
        #undef P_UNSIGNEDINT32_T

        #define P_SIGNEDINT8_T  __int8 
        #define P_SIGNEDINT16_T __int16
        #define P_SIGNEDINT32_T __int32
        #define P_SIGNEDINT64_T __int64

        #define P_UNSIGNEDINT8_T  unsigned __int8
        #define P_UNSIGNEDINT16_T unsigned __int16
        #define P_UNSIGNEDINT32_T unsigned __int32
        #define P_UNSIGNEDINT64_T unsigned __int64


    #endif
#endif

#elif defined (PANTSU_MICROARCHITECTURE_32BIT)

    #define P_POINTERSIZE_T P_UNSIGNEDINT32_T

#elif defined (PANTSU_MICROARCHITECTURE_64BIT)
    
    #define P_POINTERSIZE_T P_UNSIGNEDINT64_T

#endif

typedef P_POINTERSIZE_T __pmagic;

typedef P_SIGNEDINT8_T  __pint8;
typedef P_SIGNEDINT16_T __pint16;
typedef P_SIGNEDINT32_T __pint32;

typedef P_UNSIGNEDINT8_T  __puint8;
typedef P_UNSIGNEDINT16_T __puint16;
typedef P_UNSIGNEDINT32_T __puint32;

#if defined (PANTSU_COMPILER_GCC)

__extension__ typedef P_SIGNEDINT64_T __pint64;
__extension__ typedef P_UNSIGNEDINT64_T __puint64;

#else

typedef P_SIGNEDINT64_T __pint64;
typedef P_UNSIGNEDINT64_T __puint64;


/*Integer limits*/

#define P_SIGNEDINT8_MIN  (-0x7f - 1)
#define P_SIGNEDINT16_MIN (-0x7fff - 1)
#define P_SIGNEDINT32_MIN (-0x7fffffff - 1)
#define P_SIGNEDINT64_MIN (-0x7fffffffffffffff - 1)

#define P_SIGNEDINT8_MAX  0x7f
#define P_SIGNEDINT16_MAX 0x7fff
#define P_SIGNEDINT32_MAX 0x7fffffff
#define P_SIGNEDINT64_MAX 0x7fffffffffffffff

#define P_UNSIGNEDINT8_MAX  0xff
#define P_UNSIGNEDINT16_MAX 0xffff
#define P_UNSIGNEDINT32_MAX 0xffffffff
#define P_UNSIGNEDINT64_MAX 0xffffffffffffffff

#define P_INT_LEAST8_MIN  P_SIGNEDINT8_MIN  /* -128 */ 
#define P_INT_LEAST16_MIN P_SIGNEDINT16_MIN /* -32768 */
#define P_INT_LEAST32_MIN P_SIGNEDINT32_MIN /* -2147483648 */
#define P_INT_LEAST64_MIN P_SIGNEDINT64_MIN /* -9223372036854775808 */ 

#define P_INT_LEAST8_MAX  P_SIGNEDINT8_MAX  /* 127 */ 
#define P_INT_LEAST16_MAX P_SIGNEDINT16_MAX /* 32767 */
#define P_INT_LEAST32_MAX P_SIGNEDINT32_MAX /* 2147483647 */
#define P_INT_LEAST64_MAX P_SIGNEDINT64_MAX /* 9223372036854775807 */

#define P_INT_FAST8_MAX  P_UNSIGNEDINT8_MAX  /* 255 */ 
#define P_INT_FAST16_MAX P_UNSIGNEDINT16_MAX /* 65535 */
#define P_INT_FAST32_MAX P_UNSIGNEDINT32_MAX /* 4294967295 */
#define P_INT_FAST64_MAX P_UNSIGNEDINT64_MAX /* 18446744073709551615 */

#endif /*PANTSU_COMPILER_GCC*/

#endif /*UNKNOWN compiler and architecture*/

#endif /*PANTSU_INT_INCLUDED*/
