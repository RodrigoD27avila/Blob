struct reg {
	int i,j,k,l;
};

int main()
{
	register struct reg reg = {10,20,30,40};
	return reg.i;
}
