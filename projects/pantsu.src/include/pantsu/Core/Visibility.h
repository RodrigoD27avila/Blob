#ifndef PANTSU_CORE_VISIBILITY_H
#define PANTSU_CORE_VISIBILITY_H

#ifndef PANTSU_CORE_H
        #error "You need to include pantsu/Core.h first."
#endif

#ifdef PANTSU_WINDOWS_PLATFORM
	#ifdef PANTSU_BUILD_DLL 
		#ifdef PANTSU_COMPILER_GCC
			#define DLL_PUBLIC __attribute__ ((dllexport))
		#else
			// Note: actually gcc seems to also
			// supports this syntax.
			#define DLL_PUBLIC __declspec(dllexport)
		#endif // PANTSU_COMPILER_GCC
	#else
		#ifdef PANTSU_COMPILER_GCC
                        #define DLL_PUBLIC __attribute__ ((dllimport))
                #else
                        // Note: actually gcc seems to also
                        // supports this syntax.
                        #define DLL_PUBLIC __declspec(dllimport)
                #endif // PANTSU_COMPILER_GCC
	// not have DLL_LOCAL
	#define DLL_LOCAL
	#endif // PANTSU_BUILD_DLL
#else
	#if PANTSU_GCC_VERSION >= 4
		#define DLL_PUBLIC __attribute__ ((visibility ("default")))
		#define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
	#else
		#define DLL_PUBLIC
		#define DLL_LOCAL
	#endif // PANTSU_GCC_VERSION >= 4
#endif // PANTSU_BUILD_DLL

#endif // PANTSU_CORE_VISIBILITY_H
