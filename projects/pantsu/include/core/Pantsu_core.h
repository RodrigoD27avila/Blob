/**************************************************************************
 Operating Systems:

    Targets: Windows
             MacOSX
             GNU/Linux
 Compilers: 

    
    Targets: GNU Compiler Collection
             LLVM Compiler Infrastructure
             Microsoft C / Visual C++
             Open Watcom C/C++ Compiler
           
 Plataforms:

        Targets: x86
                 x86_64
                 ARM
                 MIPS
                 PowerPC

 

**************************************************************************/

#ifndef PANTSU_CORE_INCLUDED
#define PANTSU_CORE_INCLUDED

/* Operating systems */
#if defined (__WINDOWS__) || defined (WINNT) \
        || defined (__WINNT) || defined (__WINNT__) || defined (__CYGWIN__)

    #define PANTSU_OS_WINDOWS 1
    #define PANTSU_OS_NAME "Microsoft Windows"

#elif defined (__APPLE__) && defined (__MACH__)

    #define PANTSU_OS_APPLE 1
    #define PANTSU_OS_NAME "Mac OS X"

#elif defined (linux) || defined (__linux) || defined (__linux__) \
    || defined (__gnu_linux__)

    #define PANTSU_OS_LINUX 1
    #define PANTSU_OS_NAME "GNU/Linux"

#endif


/* Architecture */

#if defined (i386) || defined (__i386) || defined (__i386__)
    
    #define PANTSU_ARCHITECTURE_X86 1
    #define PANTSU_ARCHITECTURE_NAME "x86"

#elif defined (__amd64) || defined (__amd64__) \
    || defined (__x86_64) || defined (__x86_64__)

    #define PANTSU_ARCHITECTURE_X86_64 1
    #define PANTSU_ARCHITECTURE_NAME "x86_64"

#elif defined (__arm__)

    #define PANTSU_ARCHITECTURE_ARM 1
    #define PANTSU_ARCHITECTURE_NAME "ARM"

#elif defined (mips) || defined (_mips) || defined (__mips__)

    #define PANTSU_ARCHITECTURE_MIPS 1
    #define PANTSU_ARCHITECTURE_NAME "MIPS"

#elif defined (PPC) || defined (__PPC) || defined (__PPC__)

    #define PANTSU_ARCHITECTURE_POWERPC 1
    #define PANTSU_ARCHITECTURE_NAME "PowerPC"
    
#endif

/* Compilers */

#if defined (__GNUC__)

    #define PANTSU_COMPILER_GCC 1

    #if defined (__MINGW32__)
    
        #define PANTSU_COMPILER_MINGW 1
        #define PANTSU_COMPILER_NAME  "MinGW"

    #elif defined (__CYGWIN__)

        #define PANTSU_COMPILER_CYGWIN 1
        #define PANTSU_COMPILER_NAME "Cygwin"

    #elif defined (__llvm__) || defined (__clang__)

        #define PANTSU_COMPILER_LLVM 1
        #define PANTSU_COMPILER_NAME "LLVM Compiler Infrastructure"

    #else

        #define PANTSU_COMPILER_NAME "GNU Compiler Collection"

    #endif

#elif defined (_MSC_VER)

    #define PANTSU_COMPILER_MSC 1
    #define PANTSU_COMPILER_NAME "Microsoft C / Visual C++"

    #ifndef PANTSU_OS_NAME

        #define PANTSU_OS_WINDOWS 1
        #define PANTSU_OS_NAME "Microsoft Windows"    

    #endif

    #ifndef PANTSU_ARCHITECTURE_NAME

        #if defined (_M_AMD64)
            
            #define PANTSU_ARCHITECTURE_X86_64 1
            #define PANTSU_ARCHITECTURE_NAME "x86_64"
       
        #elif defined (_M_IX86)

            #define PANTSU_ARCHITECTURE_X86 1
            #define PANTSU_ARCHITECTURE_NAME "x86"

        #endif
    #endif


#elif defined (__WATCOMC__)

    #define PANTSU_COMPILER_WATCOM 1
    #define PANTSU_COMPILER_NAME "Open Watcom C/C++ Compiler"

    #ifndef PANTSU_OS_NAME

        #if defined (__LINUX__)

            #define PANTSU_OS_LINUX 1        
            #define PANTSU_OS_NAME "GNU/Linux"

        #endif
    #endif

    #ifndef PANTSU_ARCHITECTURE_NAME
    
        #if defined (__X86__) || defined (__386__)

            #define PANTSU_ARCHITECTURE_X86 1
            #define PANTSU_ARCHITECTURE_NAME "x86"
        
        #endif
    #endif
#endif

#ifndef PANTSU_OS_NAME
    #define PANTSU_OS_NAME "unknown operating system"
    #define PANTSU_OS_UNKNOWN 1
#endif

#ifndef PANTSU_ARCHITECTURE_NAME
    #define PANTSU_ARCHITECTURE_NAME "unknown architecture"
    #define PANTSU_ARCHITECTURE_UNKNOWN 1
#endif

#ifndef PANTSU_COMPILER_NAME
    #define PANTSU_COMPILER_NAME "unknown compiler"
    #define PANTSU_COMPILER_UNKNOWN 1
#endif

#include "Pantsu_micro.h"
#include "Pantsu_misc.h"
#include "Pantsu_int.h"
#include "Pantsu_float.h"
#include "Pantsu_types.h"

#endif /*PANTSU_CORE_INCLUDED*/
