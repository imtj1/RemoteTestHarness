/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for test_helper package, it provides the utils for showing file contents and directory contents
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*"name_spaces.h"
*"string_utilities.h"
*Maintenance History:
*-------------------
*ver 1.0 : Oct 27 2018
*- first release
*/
#pragma once
#include "name_spaces.h"
#include "string_utilities.h"

class test_helper
{
public:
	static bool show_dir_contents(const common_types::path& path, const common_types::message& msg = "");
	static bool show_file_lines(const common_types::path& path, common_types::line start, common_types::line end, const common_types::message& msg = "");
};
