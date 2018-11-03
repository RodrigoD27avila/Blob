#ifndef PANTSU_CORE_PLATAFORM_H
#define PANTSU_CORE_PLATAFORM_H

#ifndef PANTSU_CORE_H
        #error "You need to include pantsu/Core.h first."
#endif

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

#endif // PANTSU_CORE_PLATAFORM_H
