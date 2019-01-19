/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for test request executive which takes in a test request and executes all of its tests
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*"dll_executive.h"
*"../Utilities/logger_provider.h"
*"../Utilities/dll_loader.h"
*"test_executive.h"
*"../Logger/logger_utils.h"
*/
#include "pch.h"
#include "dll_executive.h"
#include "../Utilities/logger_provider.h"
#include "../Utilities/dll_loader.h"
#include "test_executive.h"
#include "../Logger/logger_utils.h"

test_result_object dll_executive::execute_dll_test_request(dll_test_request* dll_test_request)
{
	if(dll_test_request == nullptr)
	{
		logger_provider::get_logger().log(warning, "Test Request not loaded");
	}
	test_executive ex{};

	const auto test_request_message = dll_test_request->get_test_request_message();
	const auto test_author = dll_test_request->get_test_author();
	logger_provider::get_logger().log(debug, "Testing Test Request::" + test_request_message);

	/*auto& logger_in_use = logger_provider::get_logger();

	logger_provider::get_logger().log(debug, "Test request log being redirected to :" + test_request_message + "_log.txt");

	std::ofstream file_stream;
	logger_utils::create_file_stream(test_request_message, file_stream);
	logger logger;
	logger_utils::configure_logger(&logger, file_stream, test_author, debug);
	logger_provider::register_logger(logger);*/

	dll_test_request->accept_test_resource(&logger_provider::get_logger());

	ex.register_tests(dll_test_request->tests());
	
	const auto test_result = ex.do_tests();

	test_executive::show_test_results(test_result);

	logger_provider::get_logger().log(debug, "Testing finished for Test Request::" + test_request_message);
	
	ex.clear_tests();

	// logger_provider::register_logger(logger_in_use);

	delete dll_test_request;
	return test_result;
}
