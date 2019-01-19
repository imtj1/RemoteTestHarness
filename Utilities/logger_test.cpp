
/*
 * Package Operations:
 * -------------------
 * This package contains the test for logger
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*"pch.h"
*"logger.h"
*"logger_provider.h"
*<iostream>
*<sstream>
*<fstream>
*/

#include "logger.h"
#include "logger_provider.h"
#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
	logger logger_i;
	logger_provider::register_logger(logger_i);
	std::ostringstream os;
	std::ofstream file_stream;
	file_stream.open("log.txt");
	logger_provider::register_stream(file_stream);
	logger_provider::register_stream(os);
	logger_provider::register_stream(std::cout);

	logger_provider::get_logger() << "logger prints with time stamp and user details" << std::endl;
	logger_provider::get_logger().log(debug, "logger prints with log level as debug");
	logger_provider::get_logger().log_file_content("logger prints file content without stamps and other user details");

	return 0;
}
