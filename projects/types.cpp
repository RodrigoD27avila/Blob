#include <iostream>
#include <set>
#include <list>
#include <map>
#include <vector>


int main()
{
    std::set<int> myset;
    myset.insert(10);
    myset.insert(20);
    myset.insert(30);
    myset.insert(11);

    std::cout << myset.size() << std::endl;
}
