#ifndef PANTSU_CORE_COMPILER_H
#define PANTSU_CORE_COMPILER_H

#ifndef PANTSU_CORE_H
	#error "You need to include pantsu/Core.h first."
#endif

#if defined (__GNUC__)
	
	#define PANTSU_COMPILER_GCC 1
	#define PANTSU_GCC_VERSION __GNUC__

	#if defined (__llvm__) || defined (__clang__)
		#define PANTSU_COMPILER_CLANG 1
		#define PANTSU_COMPILER_NAME "LLVM/Clang Compiler"

	#else
		#define PANTSU_COMPILER_NAME "GNU Compiler Collection"
	#endif

#endif // __GNUC__

#endif // PANTSU_CORE_COMPILER_H
