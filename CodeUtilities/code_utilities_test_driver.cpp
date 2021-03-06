/*
* Package Operations:
* -------------------
* This package contains the test driver for code utilities package.
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "code_utilities.h"
*  "code_utilities.h"
*  <iostream>
*  <functional>
*  "../Utilities/logger_provider.h"
*  "../TestHarness/test_executive.h"
*   <fstream> ../TestHarness/dll_test_request.h
*	code_utilities_test_provider.h"
 */
#include "pch.h"
#include "code_utilities.h"
#include <iostream>
#include <functional>
#include "../Utilities/logger_provider.h"
#include "../TestHarness/test_executive.h"
# include <fstream>
#include "code_utilities_test_provider.h"


using namespace Utilities;

int main(int argc, char* argv[])
{
	logger logger_i;
	logger_provider::register_logger(logger_i);
	std::ostringstream os;
	std::ofstream file_stream;
	file_stream.open("logNew2.txt");
	logger_provider::register_stream(file_stream);
	logger_provider::register_stream(os);
	logger_provider::register_stream(std::cout);

	test_executive ex;
	ex.register_tests(code_utilities_test_provider::get_all_code_utilities_test());

	const auto result = ex.do_tests();
	if (result.test_passed == true)
	{
		logger_provider::get_logger() << " all tests passed";
	}
	else
	{
		logger_provider::get_logger() << " at least one test failed";
	}
	return 0;
}
