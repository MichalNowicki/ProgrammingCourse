#include <iostream>
#include <thread>

//This function will be called from a thread
void newThreadFunction() {
	
	// Code run in a new thread
	// ...
	// ...

}

int main() {
	//Launch a thread
	std::thread myThread(newThreadFunction);

	// Code run in the main thread
	// ...
	// ...

	// Main threads waits until the new thread is finished
	myThread.join();

	return 0;
}