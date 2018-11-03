/*See Copyright Notice in dat.h*/

#ifndef DATCONF_H_INCLUDED
#define DATCONF_H_INCLUDED

typedef enum {
	DAT_FALSE=0,
	DAT_TRUE=1,	

}DAT_bool;

#if defined (__GNUC__)
	#define DAT_COMPILER_GCC 1
	
	#if   defined (__MINGW32__)
		#define DAT_COMPILER_MINGW  1
	#elif defined (__CYGWIN__)
		#define DAT_COMPILER_CYGWIN 1
	#endif
/*END __GNUC__*/
#elif defined (_MS_VER)
	#define DAT_COMPILER_MSC 1
/*END _MS_VER*/
#elif defined (__WATCOMC__)
	#define DAT_COMPILER_WATCOM 1
/*END __WATCOMC__*/
#else
	#define DAT_COMPILER_UNKNOWN 1
/*END UNKNOWN COMPILER*/
#endif

#if   defined (__WINDOWS__) || defined (WINNT) \
	|| defined (__WINNT) || defined (__WINNT__) || defined (__CYGWIN__)

	#define DAT_OS_WINDOWS 1
/*END WINDOWS*/
#elif defined (linux) || defined (__linux) \
	|| defined (__linux__) || defined (__gnu_linux__)

	#define DAT_OS_POSIX 1
	#define DAT_OS_LINUX 1
/*END LINUX*/
#endif

#define D_SINT8_T  signed char
#define D_SINT16_T signed short int
#define D_SINT32_T signed int
#define D_SINT64_T signed long long  int

#define D_UINT8_T  unsigned char
#define D_UINT16_T unsigned short int
#define D_UINT32_T unsigned int
#define D_UINT64_T unsigned long long int

#if    defined (DAT_COMPILER_GCC)

	/*NOTHING TO DO*/

/*END DAT_COMPILER_GCC*/
#elif defined (DAT_COMPILER_MSC) \
		|| defined (DAT_COMPILER_WATCOM)

	#undef D_SINT8_T
	#undef D_SINT16_T
	#undef D_SINT32_T
	#undef D_SINT64_T

	#undef D_UINT8_T
	#undef D_UINT16_T
	#undef D_UINT32_T
	#undef D_UINT64_T

	#define D_SINT8_T  __int8 
	#define D_SINT16_T __int16
	#define D_SINT32_T __int32
	#define D_SINT64_T __int64

	#define D_UINT8_T  unsigned __int8
	#define D_UINT16_T unsigned __int16
	#define D_UINT32_T unsigned __int32
	#define D_UINT64_T unsigned __int64

/*END DAT_COMPILER_MSC || DAT_COMPILER_WATCOM*/
#endif

typedef D_SINT8_T  __dsint8;
typedef D_SINT16_T __dsint16;
typedef D_SINT32_T __dsint32;

typedef D_UINT8_T  __duint8;
typedef D_UINT16_T __duint16;
typedef D_UINT32_T __duint32;

#if defined (DAT_COMPILER_GCC)
	__extension__ typedef D_SINT64_T __dsint64;
	__extension__ typedef D_UINT64_T __duint64;
/*END COMPILER GCC*/
#else
	typedef D_SINT64_T __dint64;
	typedef D_UINT64_T __duint64;
#endif

typedef __dsint8  DAT_Sint8; 
typedef __dsint16 DAT_Sint16;
typedef __dsint32 DAT_Sint32;
typedef __dsint64 DAT_Sint64;

typedef __duint8  DAT_Uint8; 
typedef __duint16 DAT_Uint16;
typedef __duint32 DAT_Uint32;
typedef __duint64 DAT_Uint64;

#endif /*DATCONF_H_INCLUDED*/
