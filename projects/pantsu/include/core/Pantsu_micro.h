#ifndef PANTSU_MICRO_INCLUDED
#define PANTSU_MICRO_INCLUDED

#if !defined (PANTSU_COMPILER_UNKNOWN) \
        && !defined (PANTSU_ARCHITECTURE_UNKNOWN)

#if defined (PANTSU_ARCHITECTURE_X86)
        
    #define PANTSU_MICROARCHITECTURE_32BIT 1
    #define PANTSU_MICROARCHITECTURE_I386 1

    #if defined (PANTSU_COMPILER_GCC)
            
       #if defined (__i486) || defined (__i486__)

            #define PANTSU_MICROARCHITECTURE_I486 1
            #define PANTSU_MICROARCHITECTURE_NAME "i486"

            #define PANTSU_MICROARCHITECTURE_CPU_NAME "i486" 
      
       #elif defined (__i586) || defined (__i586__)

            #define PANTSU_MICROARCHITECTURE_i586 1
            #define PANTSU_MICROARCHITECTURE_NAME "i586"

            #if defined (__pentium) || defined (__pentium__)

                #define PANTSU_MICROARCHITECTURE_CPU_NAME "pentium"
            
            #else

                #define PANTSU_MICROARCHITECTURE_CPU_NAME "i586"  
                
            #endif

        #elif defined (__i686) || defined (__i686__)
            
            #define PANTSU_MICROARCHITECTURE_i686 1
            #define PANTSU_MICROARCHITECTURE_NAME "i686"
        
            #ifdef defined (__pentiumpro) || defined (__pentiumpro__)

                #define PANTSU_MICROARCHITECTURE_CPU_NAME "pentiumpro cpu"
 
            #else

                #define PANTSU_MICROARCHITECTURE_CPU_NAME "i686"

            #endif
   
        #elif defined (__pentium4) || defined (__pentium4__)

            #define PANTSU_MICROARCHITECTURE_PENTIUM4 1
            #define PANTSU_MICROARCHITECTURE_NAME "i386"

            #define PANTSU_MICROARCHITECTURE_CPU_NAME "pentium 4"

        #elif defined (__nocona) || defined (__nocona__)
            
            #define PANTSU_MICROARCHITECTURE_NOCONA 1
            #define PANTSU_MICROARCHITECTURE_NAME "i386"

            #define PANTSU_MICROARCHITECTURE_CPU_NAME "nocona based cpu"

        #elif defined (__geode) || defined (__geode__)

            #define PANTSU_MICROARCHITECTURE_GEODE 1
            #define PANTSU_MICROARCHITECTURE_NAME "i386"

            #define PANTSU_MICROARCHITECTURE_CPU_NAME "geode"
                
        #else
            
            #define PANTSU_MICROARCHITECTURE_NAME "i386"

            #if defined (__k6) || defined (__k6__)
                
                #define PANTSU_MICROARCHITECTURE_K6 1

                #if defined (__k6_2)

                    #define PANTSU_MICROARCHITECTURE_CPU_NAME "k6-2"        

                #elif defined (__k6_3)

                    #define PANTSU_MICROARCHITECTURE_CPU_NAME "k6-3"        
        
                #else

                    #define PANTSU_MICROARCHITECTURE_CPU_NAME "k6"

                #endif

            #elif defined (__athlon) || defined (__athlon__)

                #define PANTSU_MICROARCHITECTURE_ATHLON 1
                #define PANTSU_MICROARCHITECTURE_CPU_NAME "athlon"

            #else

                #define PANTSU_MICROARCHITECTURE_CPU_NAME "i386"

            #endif    
        #endif

    #elif defined (PANTSU_COMPILER_WATCOM)

        #if defined (__386__) || defined (M_I386)

            #define PANTSU_MICROARCHITECTURE_NAME "x86 32-bit"

            #define PANTSU_MICROARCHITECTURE_CPU_NAME "x86 32-bit cpu"

        #endif
    
    #else

        #define PANTSU_MICROARCHITECTURE_NAME "x86"
        #define PANTSU_MICROARCHITECTURE_CPU_NAME "x86 cpu"

    #endif
        
#elif defined (PANTSU_ARCHITECTURE_X86_64)
        
    #define PANTSU_MICROARCHITECTURE_64BIT 1
    #define PANTSU_MICROARCHITECTURE_AMD64 1
    #define PANTSU_MICROARCHITECTURE_NAME "amd64/intel64"

    #if defined (PANTSU_COMPILER_GCC)

        #if defined (__nocona) ||  defined (__nocona__)

            #define PANTSU_MICROARCHITECTURE_CPU_NAME "nocona" 

        #elif defined (__core2) || defined (__core2__)
        
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "core2" 
    
        #elif defined (__corei7) || defined (__corei7__)
        
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "corei7" 

        #elif defined (__atom) || defined (__atom__)
        
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "atom" 
    
        #elif defined (__k8) || defined (__k8__)
        
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "k8" 
    
        #elif defined (__amdfam10) || defined (__amdfam10__)
        
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "amdfam10" 
    
        #elif defined (__bdver1) || defined (__bdver1__)
        
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "bdver1" 
    
        #elif defined (__bdver2) || defined (__bdver2__)
        
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "bdver2" 
    
        #elif defined (__btver1) || defined (__btver1__)
        
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "btver1" 

        #else

            #define PANTSU_MICROARCHITECTURE_CPU_NAME "amd64"           
        #endif
    #else

        #define PANTSU_MICROARCHITECTURE_CPU_NAME "amd64 cpu"

    #endif

#elif defined (PANTSU_ARCHITECTURE_ARM)

    #if defined (PANTSU_COMPILER_GCC)

        /*Just for now*/
        #define PANTSU_MICROARCHITECTURE_32BIT 1
        #define PANTSU_MICROARCHITECTURE_NAME "arm"
        #define PANTSU_MICROARCHITECTURE_CPU_NAME "32 bit arm cpu"

    #endif /*PANTSU_COMPILER_GCC*/

#elif defined (PANTSU_ARCHITECTURE_MIPS)

    #if defined (PANTSU_COMPILER_GCC)
        
        #if defined (__mips64)

            #define PANTSU_MICROARCHITECTURE_64BIT 1
            #define PANTSU_MICROARCHITECTURE_NAME "mips"
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "64 bit mips cpu"  

        #else
            
            #define PANTSU_MICROARCHITECTURE_32BIT 1
            #define PANTSU_MICROARCHITECTURE_NAME "mips"
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "32 bit mips cpu"

        #endif
    #endif /*PANTSU_COMPILER_GCC*/


#elif defined (PANTSU_ARCHITECTURE_POWERPC)

    #if defined (PANTSU_COMPILER_GCC)

        #if defined (_ARCH_PPC64)

            #define PANTSU_MICROARCHITECTURE_64BIT 1
            #define PANTSU_MICROARCHITECTURE_NAME "powerpc"
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "64 bit power cpu"  

        #else

            #define PANTSU_MICROARCHITECTURE_32BIT 1
            #define PANTSU_MICROARCHITECTURE_NAME "powerpc"
            #define PANTSU_MICROARCHITECTURE_CPU_NAME "32 bit power cpu"  

        #endif

    #endif /*PANTSU_COMPILER_GCC*/

#endif /*PANTSU_ARCHITECTURES*/

#endif /*UNKNOWN compiler and architecture*/


#ifndef PANTSU_MICROARCHITECTURE_NAME
    #define PANTSU_MICROARCHITECTURE_NAME "unknown microarchitecture"
    #define PANTSU_MICROARCHITECTURE_UNKNOWN 1
#endif

#ifndef PANTSU_MICROARCHITECTURE_CPU_NAME
    #define PANTSU_MICROARCHITECTURE_CPU_NAME "unknown cpu"
    #define PANTSU_MICROARCHITECTURE_CPU_UNKNOWN 1
#endif

#endif /*PANTSU_MICRO_INCLUDED*/
