#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for test result object which contains failed tests and return and status of all tests executed
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* "test_item.h"
* Maintenance History:
* -------------------
* ver 1.0 : Oct 27 2018
* - first release
*/
#include "test_item.h"

struct test_result_object
{
	bool test_passed = true;
	std::vector<std::string> failed_tests{};
};
