#include <iostream>
#include <utility>

template<class A, class B>
auto sum(const A &a, const B &b) -> decltype(a+b)
{
    return a+b;
}

int main()
{
    auto p = std::make_pair(5, "rodrigo");
    auto c = [] (int a, std::string b) {
        std::cout << a <<  " - " <<  b << std::endl;
    };

    auto add = [] (int a, int b) -> int {
        return a+b;
    };

    c(p.first, p.second);
    std::cout << sum(10,10) << std::endl;
}
