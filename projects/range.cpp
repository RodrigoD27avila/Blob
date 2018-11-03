#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <cmath>

int main()
{
    std::array<int, 100> arr;
    std::iota(arr.begin(), arr.end(), 0);

    for (auto i : arr) {
        std::cout << i << std::endl;
    }

    std::transform(arr.begin(), arr.end(), arr.begin(),
        [] (int a) -> int {
            return ::pow(a, 2);
    });

    std::generate(arr.begin(), arr.end(),
        std::rand);

    for (auto i : arr) {
        std::cout << i << std::endl;
    }
}
