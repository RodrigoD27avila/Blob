class Foo {
	int a;
public:
	explicit Foo(int a)
		: a(a) {
	}

	virtual ~Foo() {
	}
};

class Bar {
	Foo foo;
	mutable int kakaroto { 0 };
public:
	Bar(Foo foo)
		: foo(foo) {
	}

	int barbar() const {
		kakaroto += 1;
		return kakaroto;
	}
};

int main()
{
	Foo f{1};
	Bar b(Foo {1});
}
