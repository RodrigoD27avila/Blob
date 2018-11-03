#include "list.h"

int main()
{
	List<int> ll;
	for (int i=0; i< 1000000; i++) {
		ll.append(i);
	}
}
