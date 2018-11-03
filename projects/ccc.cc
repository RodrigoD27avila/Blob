#include <iostream>

using namespace std;

class Aaa
{
  public:
    int a;
    int b;
    int c;
};

class Bbb : public Aaa
{
  public:
    int d;
    int e;
    int f;
};

void
AaatoBbb ()
{
  Aaa *a = new Aaa();
  Bbb *b = new Bbb();
  
  a->a = 1;
  a->b = 1;
  a->c = 1;
  
  b = static_cast<Bbb*>(a);
  
  cout << b->a << endl;
  cout << b->b << endl;
  cout << b->c << endl;
}

void
BbbtoAaa()
{
  Aaa *a = new Aaa();
  Bbb *b = new Bbb();
  
  b->a = 1;
  b->b = 1;
  b->c = 1;
  
  a = dynamic_cast<Bbb*>(b);
  
  cout << &a->a << endl;
  cout << &a->b << endl;
  cout << &a->c << endl;
  cout << endl;
  cout << &b->a << endl;
  cout << &b->b << endl;
  cout << &b->c << endl;
}

int
main()
{
  AaatoBbb();
  cout << "------" << endl;
  BbbtoAaa();
  return 0;
}
