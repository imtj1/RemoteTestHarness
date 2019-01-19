/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for test_executor, a class which execute test in a try catch block
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*"pch.h"
*<string>
*"test_executor.h"
*"test_item.h"
*"../Utilities/logger_provider.h"
*/
#include "pch.h"
#include <string>
#include "test_executor.h"
#include "test_item.h"
#include "../Utilities/logger_provider.h"

 // -----< executes test item and and calls test() function of test interface>
bool test_executor::execute(const test_item test_item)
{
	auto test_p = test_item.test_p;
	const auto test_name = test_item.test_name;

	auto result = false;
	try
	{
		logger_provider::get_logger().log(debug, "Testing :: " + test_name);
		result = test_p->test();
		check(result, test_name);
	}
	catch (std::exception& ex)
	{
		check(false, test_name);
		logger_provider::get_logger().log(warning, test_name + " threw exception" + ex.what());
	}
	return result;
}
//----< display test results >---------------------------------------

void test_executor::check(const bool result, const std::string test_name)
{
	if (result)
		logger_provider::get_logger().log(debug, test_name + " :: passed");
	else
		logger_provider::get_logger().log(debug, test_name + " :: failed");
}

