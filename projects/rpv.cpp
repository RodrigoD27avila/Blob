#include <stdio.h>
#include <string.h>

struct MyStruct {
	int a, b, c, d, e, f, g;
};

MyStruct get_by_val();
MyStruct *get_by_ptr();
MyStruct &get_by_ref();

int main()
{
	MyStruct m1  = get_by_val();

	MyStruct m2;
	memcpy(&m2, get_by_ptr(), sizeof(MyStruct));

	MyStruct m3 = get_by_ref();

	printf("%i, %i, %i, %i\n", m1.a, m1.b, m1.c, m1.d);
	printf("%i, %i, %i, %i\n", m2.a, m2.b, m2.c, m2.d);
	printf("%i, %i, %i, %i\n", m3.a, m3.b, m3.c, m3.d);
}

MyStruct get_by_val()
{
	MyStruct m = {0,1,2,3,4,5,6};
	return m;
}

MyStruct *get_by_ptr()
{
	MyStruct *m = new MyStruct();
	return auto_ptr<MyStruct>(m);
}

MyStruct &get_by_ref()
{
	MyStruct *m  = new MyStruct();//= {0,1,2,3,4,5,6};
	return (*m);
}
