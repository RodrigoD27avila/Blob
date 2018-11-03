#include <functional>

class Foo {
public:
	virtual int doit() {return 0;}
	virtual int notdoit_itsalonglongname() final {return 0;}
};

class Bar : public Foo {
public:
	int doit() override {return 1;}
};


template<class A, class B>
	auto sum (A a, B b) -> decltype(a+b)
{
	return a+b;
}


void render()
{

}


int main()
{
	Foo f;
	f.doit();
	f.notdoit_itsalonglongname();

	Bar b;
	b.notdoit_itsalonglongname();

	decltype(b) kk;
	kk.doit();

	std::function<void()> rfunc = render;
	rfunc();

	std::function<int(Foo&)> ifunc = std::mem_fn(&Foo::doit);
	ifunc(f);

	return b.doit();
}
