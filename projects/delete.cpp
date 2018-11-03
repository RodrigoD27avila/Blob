int main()
{
	int *array = new int[50];
	int *myint = new int;

	delete myint;
	delete[] array;
}
