#include <iostream>
#include <memory>

class Foo {
  public:
    Foo() {
    }

    virtual ~Foo() {
    }

    virtual void f() {
        std::cout << "Foo::f()" << std::endl;
    }
};

class Bar : public Foo {
  public:
    Bar() : Foo() {
    }

    virtual ~Bar() {
    }

    virtual void f() override {
        std::cout << "Bar::f()" << std::endl;
    }
};

class Boo : public Bar {
  public:
    Boo() : Bar() {
    }

    virtual ~Boo() {
    }

    virtual void f() override {
        std::cout << "Boo::f()" << std::endl;
    }
};

int main()
{
	std::unique_ptr<Boo> b(new Boo);
	Foo *f = dynamic_cast<Foo *>(b.get());
	f->f();
}
