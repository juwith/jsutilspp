#include <iostream>
#include <sstream>
#include <fstream>

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
	std::string line;
	std::size_t found;

	std::ostringstream setting_file;
	setting_file << "./mysetting";
	std::ifstream settings(setting_file.str().c_str());
	if( !settings.fail() && !settings.eof())
	{
		while( std::getline(settings, line) ) {
			found = line.find("#");
			if( found != std::string::npos ) {
				line = line.substr(found + 1);
				continue;
			}
			found = line.find("my:age");
			if( found != std::string::npos ) {
				found = line.find("=");
				line = line.substr(found + 1);
				//atoi(line.c_str());
				std::cout << "found: " << line.c_str() << std::endl;

				continue;
			}
			found = line.find("my:name");
			if( found != std::string::npos ) {
				found = line.find("=");
				line = line.substr(found + 1);
				std::cout << "found: " << line.c_str() << std::endl;

				continue;
			}
		}
	}
	
	std::cout << line << std::endl;
	return 0;
}
