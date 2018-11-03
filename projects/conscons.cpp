class Foo {
public:
	int result;
	virtual const void add(const int * const a, const int * const b) const  final{
	}
};


int main()
{
	int a = 10, b = 11;
	Foo f;
	f.add(&a, &b);
}
