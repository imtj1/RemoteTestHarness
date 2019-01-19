/*
* Package Operations:
* -------------------
* This package contains the implementation for time util.
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "time_util.h"
*   <chrono>
*   <time.h>
 */
#include "pch.h"
#include "time_util.h"
#include <chrono>
#include <time.h>

 // -----< now_time returns the current time needed for logging
std::string time_util::now_time()
{
	const auto today = std::chrono::system_clock::now();
	time_t tt;
	tt = std::chrono::system_clock::to_time_t(today);
	char output_char_array[26];
	ctime_s(output_char_array, sizeof(output_char_array), &tt);
	std::string output_string(output_char_array);
	if (!output_string.empty() && output_string[output_string.length() - 1] == '\n') {
		output_string.erase(output_string.length() - 1);
	}
	return output_string;
}
