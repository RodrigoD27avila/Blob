#include <boost/array.hpp>

int main()
{
  const int size = 10;
  boost::array<double,size> myArray;
  for (int i=0; i<size; ++i) myArray.at(i)=i; //Checks range
  return 0;
}
