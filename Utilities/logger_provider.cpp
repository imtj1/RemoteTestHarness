/* Package Operations:
 * -------------------
 * This package contains the implementation for the provider of logger class instance
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*logger_provider.h
*/
#include "logger_provider.h"

logger* logger_provider::logger_v_ = nullptr;

// -----< returns the instance of logger
logger& logger_provider::get_logger()
{
	if (logger_v_ == nullptr)
	{
		logger_v_ = new logger;
	}
	return *logger_v_;
}

// -----< registers the instance of logger
void logger_provider::register_logger(logger& logger)
{
	logger_v_ = &logger;
}

// -----< registers the output streams of logger
void logger_provider::register_stream(std::ostream& o_stream)
{
	logger_v_->register_stream(o_stream);
}

// -----< registers the user of logger
void logger_provider::register_user(const std::string& user_name)
{
	logger_v_->register_user(user_name);
}

// -----< sets the log level of the logger
void logger_provider::set_log_level(const log_level log_level_param)
{
	logger_v_->set_log_level(log_level_param);
}
