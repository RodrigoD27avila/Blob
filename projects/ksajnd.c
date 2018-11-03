static void bar()
{
    int a = 0xfff7;
    a |= 0x6777;
}

inline void foo()
{
    for (;;)
    {
        bar();
        break;
    }
}


int main()
{
    foo();
    return 0;
}
