struct Bar;

struct Foo {
	int a,b,c;
	struct Bar *bar;
};

void prints(struct Bar *bar);
