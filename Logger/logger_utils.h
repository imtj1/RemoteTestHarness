#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for the utilities provided for logger like configure and create file stream
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* <string>
*  "../Utilities/log_level.h"
* "../Utilities/logger.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : 11 Nov 2018
* - first release
*/
#include <string>
#include "../Utilities/log_level.h"
#include "../Utilities/logger.h"
#include <fstream>

class logger_utils
{
public:
	static void configure_logger(logger*, std::ofstream& file_stream, const std::string& user_name, log_level log_level);
	static std::string create_file_stream(const std::string& value, std::ofstream& file_stream);
};

