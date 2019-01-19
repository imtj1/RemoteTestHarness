/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for demo_requirements_test_provider, a class which provides all test cases related to code utilities
 * ---------------
 * @author : Tony Joseph
 * Language:    Visual C++, Visual Studio 2010
 * Platform:    Apple Mac Book Air Intel core i5 Parallels VM
 * version: 1.0
 *  Required Files:
 *  -------------------
 *  "demo_requirements_test_code.h"
 *  "../Utilities/test_helper.h"
 *  "../TestHarness/test_executive.h"
  "../TestHarness/test_request_executor.h"
  "../Logger/logger_utils.h"
 */
#include "pch.h"
#include "demo_requirements_test_code.h"
#include <string>
#include "../TestHarness/test_executive.h"
#include "demo_requirements_test_provider.h"

int main(int argc, char* argv[])
{
	std::string path = "..";
	logger logger_i;
	logger_provider::register_logger(logger_i);
	std::ostringstream os;
	std::ofstream file_stream;
	file_stream.open("log.txt");
	logger_provider::register_stream(file_stream);
	logger_provider::register_stream(os);
	logger_provider::register_stream(std::cout);

	test_executive te{};
	te.register_tests(demo_requirements_test_provider::get_all_demo_requirement_tests());

	const auto result = te.do_tests();
	if (result.test_passed == true) {
		logger_provider::get_logger().log(debug, " all tests passed");
	}
	else {
		logger_provider::get_logger().log(debug, " at least one test failed");
	}
	return 0;
}
