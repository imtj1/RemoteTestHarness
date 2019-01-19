#pragma once
#include <string>
#include <time.h>
#include <chrono>

class time_util_1
{
public:
	static std::string now_time();
};

inline std::string time_util_1::now_time()
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