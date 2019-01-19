/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for logger utils
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* "pch.h"
* "logger_utils.h"
* "../TestHarness/dll_test_request.h"
* <iostream>
*/
#include "logger_utils.h"
#include "../TestHarness/dll_test_request.h"
#include <iostream>

std::string log_file_extension = "_log.txt";
void logger_utils::configure_logger(logger* logger, std::ofstream& file_stream, const std::string& user_name, const log_level log_level)
{
	(*logger).set_log_level(log_level);
	(*logger).register_user(user_name);
	(*logger).register_stream(file_stream);
	(*logger).register_stream(std::cout);
}

std::string logger_utils::create_file_stream(const std::string& value, std::ofstream& file_stream)
{
	file_stream.open(value + log_file_extension);
	return value + log_file_extension;
}

