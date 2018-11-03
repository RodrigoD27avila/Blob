#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	auto f = []() {
		std::chrono::milliseconds millis(2000);
		std::this_thread::sleep_for(millis);
	};

	std::thread t1(f);
	std::thread t2(f);
	std::thread t3(f);

	t1.join();
	t2.join();
	t3.join();
}
