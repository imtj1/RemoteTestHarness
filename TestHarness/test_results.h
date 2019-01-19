#pragma once
/*
 * Package Operations:
 * -------------------
 * This package wraps the resulta of the tests into a single object
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "test_result_object.h"
* "test_item.h"
* Maintenance History:
* -------------------
* ver 1.0 : Oct 27 2018
* - first release
*/
#include "test_result_object.h"

class test_results
{
public:
	bool tests_passed = true;
	std::string log_file_name;
	std::vector<test_result_object> results{};
};