#include <iostream>


extern "C" void cdecl() __attribute__((cdecl));
void cdecl()
{
	std::cout << "cdecl" << std::endl;
}

extern "C" void stdcall() __attribute__((stdcall));
void stdcall()
{
	std::cout << "stdcall" << std::endl;
}

extern "C" void fastcall() __attribute__((fastcall));
void fastcall()
{
	std::cout << "fastcall" << std::endl;
}


class Foo {
public:
	void printfoo();
};

int main()
{
	std::string foo = "Rodrigo D'avila";
	std::cout << foo << std::endl;
	Foo f;
	f.printfoo();
	cdecl();
	stdcall();
	fastcall();
}

void Foo::printfoo() {
	std::cout << "FOO ROCKS!!" << std::endl;
}
