template<class T> class Foo
{
public:
    T _t;
    Foo(const T &t);
};

int main()
{
    Foo<int> foo(int i);
    return 0;
}

template<class T> Foo<T>::Foo(const T &t)
{
    _t = t;
}
