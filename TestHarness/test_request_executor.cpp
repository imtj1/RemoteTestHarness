/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for test_request_executor
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*"test_request_executor.h"
*"dll_executive.h" 
*"../Utilities/dll_loader.h" 
*"../Utilities/logger_provider.h" 
*/
#include "pch.h"
#include "test_request_executor.h"
#include "dll_executive.h"
#include "../Utilities/dll_loader.h"
#include "../Utilities/logger_provider.h"
#include "../Logger/logger_utils.h"

test_results test_request_executor::execute_test_request(Testing::TestRequest test_request, std::string dll_location)
{
	std::ofstream file_stream;
	const auto log_file_name = logger_utils::create_file_stream(test_request.name(), file_stream);
	logger logger;
	logger_utils::configure_logger(&logger, file_stream, test_request.author(), debug);
	logger_provider::register_logger(logger);
	dll_loader dll_loader;
	test_results test_results;
	test_results.log_file_name = log_file_name;
	for (const auto a_dll : test_request.request.valueRef())
	{
		auto dll_spec = dll_location + "/" + a_dll;
		logger_provider::get_logger().log(debug, "Found Dll at location : " + dll_spec);
		const auto dll_test_request = dll_loader.load_dll_test_request(dll_spec);
		logger_provider::get_logger().log(debug, "Executing test request from Dll : " + dll_spec);
		test_results.results.push_back(dll_executive::execute_dll_test_request(dll_test_request));
		logger_provider::get_logger().log(debug, "Test request execution finished : " + dll_spec);
		dll_loader.clear();
	}
	return test_results;
}
