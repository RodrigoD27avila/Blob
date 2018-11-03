#include <iostream>
#include <thread>

void do_some_work()
{
	std::cout << "Some Work" << std::endl;
}

int main()
{
	std::thread mythread(do_some_work);
	mythread.detach();
}

