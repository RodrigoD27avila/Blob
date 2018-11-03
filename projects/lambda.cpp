#include <iostream>
#include <future>
#include <thread>
#include <chrono>

struct Foo final {
	
};

int main()
{
	auto print_ten = [] (char c, int ms) {
		for (int i=0; i<10; i++) {
			std::this_thread::sleep_for(
				std::chrono::milliseconds(ms)	
			);

			std::cout << c;
		}
	};


	std::future<void> async1 = std::async(std::launch::async,
		print_ten, '*', 100);
	
	std::future<void> async2 = std::async(std::launch::async,
		print_ten, '@', 200);

	async1.get();
	async2.get();

	std::cout << std::endl;
}
