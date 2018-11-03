int sumsum(int a, int b, int c, int d)
{
	return a+b+c+d;
}

int callsumsum()
{
	int a = 10;
	int b = 11;
	int c = 12;
	int d = 13;
	int e = sumsum(a,b,c,d);

	return sumsum(e+a, e+b, e+c, e+d);
}

void ifsifs()
{
	int a = 10;
	int b = 11;

	if (a == b) {
		return;
	}
	else if (a < b) {
		return;
	}
	else if (a > b) {
		return;
	}
	else if (a >= b) {
		return;
	}
	else if (a <= b) {
		return;
	}

	else if (a != b) {
		return;
	}
}

int main(int argc, char **argv)
{
	ifsifs();
	return callsumsum();
}
