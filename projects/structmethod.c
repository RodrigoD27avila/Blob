const struct foo {
	int a, b, c;
} * getfoo();

const struct foo *getfoo()
{
	static struct foo f = {10, 10, 10};
	return &f;
}

int main() {
	return getfoo()->a;
}
