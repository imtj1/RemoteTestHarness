/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for test_harness_utils, a class which the necessary utilities for the test harness project
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*"test_harness_utils.h"
*"../Utilities/logger_provider.h"
*/

#include "pch.h"
#include "test_harness_utils.h"
#include "../Utilities/logger_provider.h"
#include "test_results.h"

// -----< displays the test result from the test result object
void test_harness_utils::display_test_results(test_result_object test_result_object)
{
	if (test_result_object.test_passed)
	{
		logger_provider::get_logger().log(debug, "All tests have passed");
	}
	else
	{
		logger_provider::get_logger().log(warning, "The following tests have failed");
		for(auto failed_items:test_result_object.failed_tests)
		{
			logger_provider::get_logger().log(warning, failed_items);
		}
	}
}

std::string test_harness_utils::get_test_results(test_result_object test_result_object)
{
	std::string result_string;
	if (test_result_object.test_passed)
	{
		result_string+="All tests have passed";
	}
	else
	{
		logger_provider::get_logger().log(warning, "The following tests have failed");
		for (const auto failed_items : test_result_object.failed_tests)
		{
			result_string+=failed_items;
		}
	}
	return result_string;
}

std::string test_harness_utils::get_result_string(test_results test_results)
{
	std::string result_string;
	auto passed = true;
	for (auto result : test_results.results)
	{
		if (result.test_passed) continue;
		passed = false;
		for (const auto failed_test : result.failed_tests)
			result_string += failed_test + ", ";
	}
	if (passed)
	{
		result_string = "All tests have passed";
	}
	else
	{
		result_string = "The following tests have failed - " + result_string;
	}
	return result_string;
}

