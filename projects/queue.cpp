#include <iostream>
#include <queue>

int main()
{
	std::queue<int> myqueue;
	myqueue.push(10);
	myqueue.push(11);
	myqueue.push(12);

	while (!myqueue.empty()) {
		std::cout << myqueue.front() << std::endl;
		myqueue.pop();
	}

	std::priority_queue< int, std::vector<int>, std::less<int> > mypqueue;
	mypqueue.push(4);
	mypqueue.push(3);
	mypqueue.push(9);

	while (!mypqueue.empty()) {
		std::cout << mypqueue.top() << std::endl;
		mypqueue.pop();
	}

}
