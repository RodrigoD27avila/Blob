template<class T>
class Teste {
private:
	T a;
	T b;
public:
	Teste(const T& a, const T& b)
	{
		this->a = a;
		this->b = b;
	}

	T sum();
	//{
	//	return a+b;
	//}
};

template<class T>
T Teste<T>::sum()
{
	T result = a+b;
	return result;
}

