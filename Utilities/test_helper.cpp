/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for test_helper package
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*"name_spaces.h"
*"string_utilities.h"
 */
#include "pch.h"
#include <string>
#include "../CppCommWithFileXfer/Utilities/FileSystem/FileSystem.h"
#include "test_helper.h"
#include "logger_provider.h"

 // -----< show_dir_contents returns the files under a given directory
bool test_helper::show_dir_contents(const common_types::path& path, const common_types::message& msg)
{
	if (msg.size() > 0)
		Utilities::title(msg);
	logger_provider::get_logger().log_file_content("\n  " + FileSystem::Path::getFullFileSpec(path));
	if (!FileSystem::Directory::exists(path))
	{
		logger_provider::get_logger().log_file_content("\n  path does not exist");
		return false;
	}

	common_types::files files = FileSystem::Directory::getFiles(path);
	for (auto file : files)
	{
		std::string ext = FileSystem::Path::getExt(file);
		if (ext == "h" || ext == "cpp" || ext == ".xaml" || ext == ".cs")
			logger_provider::get_logger().log_file_content("\n    " + file);
	}
	logger_provider::get_logger().log_file_content("\n");
	return true;
}
//----< show specified contiguous lines from a code file >---------

bool test_helper::show_file_lines(const common_types::path& path, common_types::line start, common_types::line end, const common_types::message& msg)
{
	if (msg.size() > 0)
		Utilities::title(msg);
	logger_provider::get_logger().log_file_content("\n  " + FileSystem::Path::getFullFileSpec(path));

	std::ifstream file(path);
	if (!file.good())
	{
		logger_provider::get_logger().log_file_content("\n  can't open file");
		return false;
	}

	std::string line;
	size_t count = 0;
	while (std::getline(file, line))
	{
		if (++count < start) continue;
		if (count > end) break;
		logger_provider::get_logger().log_file_content("\n");
		logger_provider::get_logger().log_file_content(count);
		logger_provider::get_logger().log_file_content(" ");
		logger_provider::get_logger().log_file_content(line, true);
	}
	logger_provider::get_logger().log_file_content("\n");
	return true;
}

