#include <iostream>
#include <chrono>
#include <ctime>

long fibonacci(unsigned n)
{
	if (n < 2) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	auto start = std::chrono::system_clock::now();
	std::cout << "f(30) = " << fibonacci(30) << '\n';
	auto end = std::chrono::system_clock::now();

	std::chrono::milliseconds elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "elapsed time: " << elapsedTime.count() << " ms\n";
}