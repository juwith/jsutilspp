#include <iostream>
#include <sstream>
#include <fstream>

#include <ctime>
#include <unistd.h>

#include <chrono>

using namespace std;


#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)

int main()
{
	std::chrono::system_clock::time_point tic = std::chrono::system_clock::now();

	usleep(1000*100);

	std::chrono::system_clock::time_point toc = std::chrono::system_clock::now();

	std::chrono::duration<double> DefaultSec = toc-tic;

	std::chrono::duration<double> test;

	for(int i=0 ; i<7; i++) {
		test += DefaultSec;
	}

	printf("%f s %f ms \n", DefaultSec.count()*1000 ,test.count()*1000);

	int testid=1000;
	printf("%d \n",testid%1000);

	return 0;
}
