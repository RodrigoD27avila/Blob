#ifndef __MYOTHERCLASS_H__
#define __MYOTHERCLASS_H__

#include "myclass.h"

namespace MyNamespace {

class MyOtherClass : MyClass {
public:
	MyOtherClass();
	~MyOtherClass();

	void print_vars();
};

} // end MyNamespace

#endif // __MYOTHERCLASS_H__
