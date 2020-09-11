#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

std::mutex mymtx;

void threadA(int* x) 
{
	
	for(int i=0; i<100; i++) {
		std::unique_lock<std::mutex> lck(mymtx);
		(*x)++;
		std::cout << "++ threadA :" << *x << std::endl;
		lck.unlock(); //can skip. but sleep will be included when user skip it.
		usleep(10*1000);
	}
}

void threadB(int* x)
{
	for(int i=0; i<100; i++) {
		std::unique_lock<std::mutex> lck(mymtx);
		(*x)--;
		std::cout << "-- threadB :" << *x << std::endl;
		lck.unlock(); //can skip. but sleep will be included when user skip it.
		usleep(10*1000);
	}
}

int main() 
{
	int x=0;

	std::thread thread1(threadA, &x);
	std::thread thread2(threadB, &x);

	thread1.join();
	thread2.join();

	std::cout << "thread exit" << std::endl;

  return 0;
}