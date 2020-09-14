#include <iostream>
#include <sstream>
#include <fstream>

#include <ctime>
#include <unistd.h>

#include <chrono>

int main()
{
	std::chrono::system_clock::time_point tic = std::chrono::system_clock::now();

	usleep(1000*100);

	std::chrono::system_clock::time_point toc = std::chrono::system_clock::now();

	std::chrono::duration<double> DefaultSec = toc-tic;


	printf("%f ms \n", DefaultSec.count()*1000);

	return 0;
}
