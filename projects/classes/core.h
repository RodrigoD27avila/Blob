#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#ifdef __cplusplus
	#define EXTERNC extern "C"
	#define BEGIN_NAMESPACE_CLASSES \
		namespace Classes {
	#define END_NAMESPACE_CLASSES \
		}
#else
	#define EXTERNC 
	#define BEGIN_NAMESPACE_CLASSES
	#define END_NAMESPACE_CLASSES
#endif

#endif // CORE_H_INCLUDED
