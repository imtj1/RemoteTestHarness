/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for test_executive, a class which the class which executes each test using test executor
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*"test_executive.h"
*"test_executor.h"
*"test_item.h"
*"../Utilities/logger_provider.h"
*"test_result_object.h"
*"test_harness_utils.h"
*/
#include "pch.h"
#include "test_executive.h"
#include "test_executor.h"
#include "test_item.h"
#include "../Utilities/logger_provider.h"
#include "test_result_object.h"
#include "test_harness_utils.h"

 // -----< registers the test for execution
void test_executive::register_test(const std::shared_ptr<test_interface> test_p, const std::string& test_name)
{
	const test_item test_item{ test_p, test_name };
	tests_container_.push_back(test_item);
	// push_back copies the test item
	// - that makes a new shared_ptr sharing the same test as the original
	// - it also makes a copy of the test name string
}

// -----< registers the test for execution
void test_executive::register_tests(std::vector<test_item> test_items)
{
	for (auto test_item : test_items)
		tests_container_.push_back(test_item);
}

// -----< registers the test for execution
void test_executive::register_test(const test_item& test_item)
{
	tests_container_.push_back(test_item);
	// push_back copies the test item
	// - that makes a new shared_ptr sharing the same test as the original
	// - it also makes a copy of the test name string
}

// -----< clears the registered tests
void test_executive::clear_tests()
{
	tests_container_.clear();
}

// -----< display the test results
void test_executive::show_test_results(const test_result_object test_result_object)
{
	test_harness_utils::display_test_results(test_result_object);
}

//----< execute each stored test >---------------------------------

test_result_object test_executive::do_tests()
{
	logger_provider::get_logger().log(debug,"Test Executive started testing");
	test_executor test_executor;
	test_result_object test_result_object;
	for (const auto item : tests_container_)
	{
		const auto test_result = test_executor.execute(item);
		if (test_result == false)
		{
			test_result_object.test_passed = false;
			test_result_object.failed_tests.push_back(item.test_name);
		}
	}
	logger_provider::get_logger().log(debug, "Test Executive finished testing");
	return test_result_object;
}
