#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myclass.h"

static const int Default_a = 10;
static const int Default_b = 11;
static const int Default_c = 12;
static const int Default_d = 13;

struct MyClassPrivate {
	int a,b,c,d;
	friend class MyClass;
};

MyClass::MyClass()
{
	priv->a = Default_a;	
	priv->b = Default_b;	
	priv->c = Default_c;	
	priv->d = Default_d;	
}

MyClass::~MyClass()
{
}

void MyClass::print()
{
	printf("%i, %i, %i, %i\n", priv.a, priv.b,
		priv.c, priv.d);
}
