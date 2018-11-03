class Dass
{
    int n[3];
    const Dass *d1;
    Dass *d2;
    const char *r;
public:
    Dass() : d1(new Dass), d2(new Dass) {}
};

int main()
{
    Dass *d = new Dass;
    delete d;
    return 0;
}
