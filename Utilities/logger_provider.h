#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for the provider of logger class instance
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* "logger.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : 11 Nov 2018
* - first release
*/

#include "logger.h"

class logger_provider
{
public:
	static logger& get_logger();
	static void register_logger(logger &logger);
	
	static void register_stream(std::ostream&);
	static void register_user(const std::string&);
	static void set_log_level(log_level);
private:
	logger_provider() = default;
	static logger* logger_v_;
};

