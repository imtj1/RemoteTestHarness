#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for test_harness_utils, a class which the necessary utilities for the test harness project
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* "test_result_object.h"
* "test_results.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : Oct 27 2018
* - first release
*   ver 2.0 : Oct 27 2018
*  - meeting new requirements
*/

#include "test_result_object.h"
#include "test_results.h"

class test_harness_utils
{
public:
	static void display_test_results(test_result_object);
	static std::string get_test_results(test_result_object test_result_object);
	static std::string get_result_string(test_results test_results);
};

