/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for test main method to test out test harness functionality.
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*"test_interface.h"
*"test_executive.h"
*<iostream>
*<fstream>
*"../Utilities/logger_provider.h"
*"../Utilities/test_helper.h"
*/
#include "pch.h"
#include "test_interface.h"
#include "test_executive.h"
#include <iostream>
#include <fstream>
#include "../Utilities/logger_provider.h"
#include "../Utilities/test_helper.h"

class test_passes : public test_interface
{
public:
	bool test() override { return true; }
};

class test_fails : public test_interface
{
public:
	bool test() override { return false; }
};

class test_req3 : public test_interface
{
	const std::string path_;
public:
	explicit test_req3(const std::string& path) : path_(path) {}
	bool test() override
	{
		const common_types::message msg = "Req #3 - tests implement ITest interface";
		const auto file_spec = path_;
		return test_helper::show_file_lines(file_spec, 1, 3, msg);
	}
};

int main()
{
	logger logger_i;
	logger_provider::register_logger(logger_i);
	std::ostringstream os;
	std::ofstream file_stream;
	file_stream.open("log.txt");
	logger_provider::register_stream(file_stream);
	logger_provider::register_stream(os);
	logger_provider::register_stream(std::cout);

	test_executive ex{};
	test_item test_item1{};

	test_item1.test_p = std::shared_ptr<test_interface>(new test_passes());
	test_item1.test_name = "test_always_passes";

	test_item test_item2;
	test_item2.test_p = std::shared_ptr<test_interface>(new test_req3("../TestHarness/test_interface.h"));
	test_item2.test_name = "test_show file";

	test_item test_item3;
	test_item3.test_p = std::shared_ptr<test_interface>(new test_fails());
	test_item3.test_name = "test_always_fails";
	ex.register_test(test_item1);
	ex.register_test(test_item2);
	ex.register_test(test_item3);
	const auto result = ex.do_tests();

	if (result.test_passed == true)
		logger_provider::get_logger().log(debug, "\n  all tests passed");
	else
		logger_provider::get_logger().log(debug, "\n  at least one test failed");
	return 0;
}
