#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declarations and definition for logger class due to template functions
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  #include <vector>
*  #include "log_level.h"
*  #include "time_util.h"
*	#include <ostream>
*  #include <iomanip>
*   Maintenance History:
*   -------------------
*   ver 1.0 : 11 Nov 2018
*  - first release
*/
#include <vector>
#include "log_level.h"
#include "time_util.h"
#include <ostream>
#include <iomanip>

class logger
{
	
public:
	template <typename T>
	logger& operator << (T const&);
	logger& operator << (std::ostream& (*pf) (std::ostream&));
	void register_stream(std::ostream&);
	template <typename T>
	void log(log_level, T const&);
	template <typename T>
	void log_file_content(T const&, bool set_width = false);
	void register_user(const std::string&);
	void set_log_level(log_level);
private:
	log_level log_level_enum_ = info;
	std::string current_user_;
	std::vector<std::ostream*> streams_;
	static std::string to_string(log_level);
	template <typename T>
	void write_to_streams(T const&, log_level log_level_param = none);
};

template <typename T>
logger& logger::operator<<(T const & value)
{
	write_to_streams(value);
	return *this;
}

template<typename T>
void logger::log(const log_level log_level_param, T const & value)
{
	if (log_level_param >= log_level_enum_) {
		write_to_streams(value, log_level_param);
	}
}

template <typename T>
void logger::log_file_content(T const& value, bool set_width)
{
	for (auto stream : streams_)
	{
		(*stream) <<std::setw(4)<< value;
	}
}

template<typename T>
void logger::write_to_streams(T const & value, const log_level log_level_param)
{
	for (auto stream : streams_)
	{
		(*stream) << std::endl;
		(*stream) << "- " << time_util::now_time();
		(*stream) << "- USER::" << current_user_ << " -";
		(*stream) << to_string(log_level_param);
		(*stream) << ": ";
		(*stream) << value;
		(*stream) << std::endl;
	}
}

inline logger& logger::operator<<(std::ostream&(*pf)(std::ostream&))
{
	for (auto stream : streams_)
	{
		(*stream) << pf;
	}
	return *this;
}

inline std::string logger::to_string(const log_level level)
{
	switch (level) {
	case warning:
		return "WARNING";
	case info:
		return "INFO";
	case debug:
		return "DEBUG";
	case error:
		return "ERROR";
	case none:
		return "";
	default:
		return "";
	}
}

inline void logger::register_stream(std::ostream& stream)
{
	streams_.push_back(&stream);
}

inline void logger::register_user(const std::string & user_name)
{
	current_user_ = user_name;
}

inline void logger::set_log_level(const log_level log_level_param)
{
	log_level_enum_ = log_level_param;
}



