struct Foo {
	void doFunction(int i, int j, char k);
};

void Foo::doFunction(int i, int j, char k)
{
	int l = i+j * k;
}

int main()
{
	Foo f;
	f.doFunction(10, 10, 2);
}

