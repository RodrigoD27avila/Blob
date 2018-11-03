#ifndef PANTSU_CORE_DATATYPES_H
#define PANTSU_CORE_DATATYPES_H

#ifndef PANTSU_CORE_H
        #error "You need to include pantsu/Core.h first."
#endif

// NULL
#define NULL (0)

//  integer 64 bits
#if PANTSU_STANDARD_C99
	typedef signed   long long int s64;
	typedef unsigned long long int u64;
#else
	#if PANTSU_COMPILER_GCC || PANTSU_COMPILER_CLANG 
		__extension__ typedef signed   long long int s64;
		__extension__ typedef unsigned long long int u64;
	#else
		#error "Don't have definition for 64 bit integer"
	#endif
#endif

// integer 8 bits
typedef signed   char s8;
typedef unsigned char u8;

// integer 16 bits
typedef signed   short s16;
typedef unsigned short u16;

// integer 32 bits
typedef signed   int s32;
typedef unsigned int u32;

#endif // PANTSU_CORE_DATATYPES_H
