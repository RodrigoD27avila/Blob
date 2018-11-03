struct aa
{
	unsigned int a:3;
};

int main()
{
	struct aa aa = {2};
	return aa.a;
}
