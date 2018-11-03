#include <iostream>
#include <future>
#include <thread>

int main()
{

	std::packaged_task<int()> task([](){
		return 7;
	});
	std::future<int> f1 = task.get_future();
	std::thread(std::move(task)).detach();

	f1.wait();
	std::cout << f1.get() << std::endl;

	auto i = int();
	std::cout << i << std::endl;
}
