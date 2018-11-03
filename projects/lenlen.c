int foo(int n)
{
	int arr[n], i;
	for (i=0; i <n; i++) {
		*(arr+i) = 10;
	}
	return *(arr+n-1);
}

int bar (int **m)
{
	*(m) = (int *)0x8000;
	return 0;
}


int main()
{
	foo(10);
	int *m;
	bar(&m);
	return *m;
	
}
