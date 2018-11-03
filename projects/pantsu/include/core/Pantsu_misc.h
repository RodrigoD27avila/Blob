#ifndef PANTSU_MISC_INCLUDED
#define PANTSU_MISC_INCLUDED

#if defined (__STDC_VERSION__)

    #if __STDC_VERSION__ >= 199901L
        
        #define PANTSU_STANDARD_C_99 1        

    #else

        #define PANTSU_STANDARD_C_89 1

    #endif

#else

    #define PANTSU_STANDARD_C_89 1
 
#endif

#if !defined (PANTSU_COMPILER_UNKNOWN) \
        && !defined (PANTSU_ARCHITECTURE_UNKNOWN)


#if defined (PANTSU_COMPILER_GCC)

    #if defined (__LITTLE_ENDIAN__)

        #define PANTSU_ORDER_LITTLE_ENDIAN 1

    #elif defined (__BIG_ENDIAN__)

        #define PANTSU_ORDER_BIG_ENDIAN 1

    #elif defined (__BYTE_ORDER__)

        #if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
                
            #define PANTSU_ORDER_LITTLE_ENDIAN 1

        #elif (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) 
            
            #define PANTSU_ORDER_BIG_ENDIAN 1

        #elif (__BYTE_ORDER__ == __ORDER_PDP_ENDIAN__)

            #define PANTSU_ORDER_PDP_ENDIAN 1

        #else

            #define PANTSU_ORDER_BY_ARCH 1

        #endif
    #endif 

#else

    #define PANTSU_ORDER_BY_ARCH 1

#endif

#if defined (PANTSU_ORDER_BY_ARCH)

    #if defined (PANTSU_ARCHITECTURE_X86) \
        || defined (PANTSU_ARCHITECTURE_X86_64)

        #define PANTSU_ORDER_LITTLE_ENDIAN 1

    #elif defined (PANTSU_ARCHITECTURE_POWERPC)

        #define PANTSU_ORDER_BIG_ENDIAN 1

    #else

        #define PANTSU_ARCHITECTURE_ORDER_BIENDIAN 1
        
        #if defined (PANTSU_ARCHITECTURE_MIPS)

            #if defined (MIPSEL) || defined (_MIPSEL) \
                || defined (__MIPSEL) || defined (__MIPSEL__)

                #define PANTSU_ORDER_LITTLE_ENDIAN 1

            #elif defined (MIPSEB) || defined (_MIPSEB) \
                || defined (__MIPSEB) || defined (__MIPSEB__)
                
                #define PANTSU_ORDER_BIG_ENDIAN 1

            #else

                #define PANTSU_ORDER_UNKNOWN_ENDIAN 1

            #endif

        #else
            
            #define PANTSU_ORDER_UNKNOWN_ENDIAN 1
            
        #endif
    #endif
#endif



#endif /*UNKNOWN compiler and architecture*/

#endif /*PANTSU_MISC_INCLUDED*/
