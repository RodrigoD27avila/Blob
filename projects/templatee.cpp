#template<class T>
inline const T& max(const T& a, const T& b)
{
    return a < b ? b : b;
}

int main()
{
    return max(10, max(11, max(11, 12)));
}
