#ifndef PANTSU_CORE_STANDARD_H
#define PANTSU_CORE_STANDARD_H

#ifndef PANTSU_CORE_H
        #error "You need to include pantsu/Core.h first."
#endif

#if __STDC_VERSION__ >= 199901L
	#define PANTSU_STANDARD_C99 1
#else
	#define PANTSU_STANDARD_C89 1
#endif

#endif // PANTSU_CORE_STANDARD_H
