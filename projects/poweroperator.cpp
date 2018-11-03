#include <iostream>
#include <string>

class Foo;
class Bar;

void operator >>(const Foo &foo, std::string &str)
{
    foo.name = str;
}
