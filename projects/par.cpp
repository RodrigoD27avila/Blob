class Foo
{
public:
    int a, b, c;
};

void foo(Foo f)
{
    f.a = 10;
    f.b = 10;
    f.c = 10;
}

void foo(Foo *f)
{
    f = new Foo();
    f->a = 10;
    f->b = 10;
    f->c = 10;
}

void foo(Foo &f)
{
    f = Foo();
    f.a = 10;
    f.b = 10;
    f.c = 10;
}

int main()
{
    return 0;
}
