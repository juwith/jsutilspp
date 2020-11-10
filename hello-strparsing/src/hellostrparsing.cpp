#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

std::map<std::string, int> getTunedValue(std::string type)
{
	std::map<std::string, int> tuned;

	std::string line;
	std::size_t found;

	std::ostringstream setting_file;
	setting_file << "mysetting";
	std::ifstream settings(setting_file.str().c_str());
	if( !settings.fail() && !settings.eof())
	{
		while( std::getline(settings, line) ) {
			found = line.find("#");
			if( found != std::string::npos ) {
				line = line.substr(found + 1);
				continue;
			}
			found = line.find(type.c_str());
			if( found != std::string::npos ) {
				std::size_t sepBegin = line.find(":");
				std::size_t sepEnd = line.find("=");

				std::string separator = line.substr(sepBegin+1, sepEnd-sepBegin-1);

				sepBegin = sepEnd;
				std::string targetVal = line.substr(sepBegin+1);
				uint32_t finetuned = atoi(targetVal.c_str());

				tuned[separator] = finetuned;
				continue;
			}

		}
	}
	return tuned;
}

/**
 *   'mysetting' file required in your path.
 *   sample ) mysetting
 *   ```
 *   # my:age=30
 *   my:name=jusang
 *   ```
 *   my:age will be ignored, my:name will be set.
**/

int main()
{
	std::map<std::string, int> tuned = getTunedValue("audio");

	std::cout << "audio information :" << std::endl;
	for (std::map<std::string,int>::iterator it=tuned.begin(); it!=tuned.end(); ++it) {
		if(it->first.compare("myval") == 0) {
			std::cout << it->second << '\n';
		}
		std::cout << it->first << " => " << it->second << '\n';
	}
	return 0;
}
