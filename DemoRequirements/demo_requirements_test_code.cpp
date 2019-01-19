/*
* Package Operations:
* -------------------
* This package contains the implementation for demo requirement tests
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
#include "../Utilities/test_helper.h"

utilities_test::test_1::test_1(std::string path) : path_(std::move(path))
{
}

bool utilities_test::test_1::test()
{
	const message msg = "Req #1 - Use C++";
	const auto path = path_ + "/TestHarness";
	return test_helper::show_dir_contents(path, msg);
}

utilities_test::test_2::test_2(std::string path) : path_(std::move(path))
{
}

bool utilities_test::test_2::test()
{
	const message msg = "Req #2 - use Windows Presentation Foundation (WPF) for all user display";
	const auto path = path_ + "/TestClient";

	const auto file_spec = path_ + "/TestClient/MainWindow.xaml";
	test_helper::show_file_lines(file_spec, 1, 50, msg);
	return test_helper::show_dir_contents(path, msg);
}

utilities_test::test_3::test_3(std::string path) : path_(std::move(path))
{
}

bool utilities_test::test_3::test()
{
	const message msg = "Req #3a - assemble the working parts from Projects #1, #2, and #3 into a Client-Server configuration";
	const auto file_spec = path_ + "/TestHarness/test_executive.cpp";
	const auto file_spec_1 = path_ + "/Utilities/dll_loader.cpp";
	const auto file_spec_2 = path_ + "/TestHarnessProcessPoolHost/process_pool_host.cpp";
	test_helper::show_file_lines(file_spec, 66, 81, msg);
	test_helper::show_file_lines(file_spec_1, 32, 49, "");
	return test_helper::show_file_lines(file_spec_2, 32, 49, "");
}

utilities_test::test_4::test_4(std::string path) : path_(std::move(path))
{
}

bool utilities_test::test_4::test()
{
	Utilities::title("Req #3b -  the Client need not wait for a reply for a TestRequest from the TestHarness before sending additional TestRequests");
	logger_provider::get_logger().log(debug, "This requirement is met when the application starts up and it runs 2 test requests fired consecutively");
	return true;
}

utilities_test::test_5::test_5(std::string path) : path_(std::move(path))
{
}

bool utilities_test::test_5::test()
{
	const message msg = "Req4 - provide a Graphical User Interface (GUI) for the client that supports selecting test libraries to send for testing, and supports displaying the test results.";

	const auto file_spec = path_ + "/TestClient/MainWindow.xaml";
	test_helper::show_file_lines(file_spec, 1, 50, msg);
	
	logger_provider::get_logger().log(debug, "This requirement is implemented in the GUI, at startup the GUI is shown and it is possible to select files from the UI for execution");

	return true;
}

utilities_test::test_6::test_6(std::string path) : path_(std::move(path))
{
}

bool utilities_test::test_6::test()
{
	const message msg = "Req #5 - provide message designs appropriate for this application. All messages are instances of the same Message class, but have a specified set of attributes and body contents suited for the intended task";

	const auto file_spec1 = path_ + "/TestHarnessProcessPoolHost/process_pool_send_receive.cpp";
	const auto file_spec2 = path_ + "/ChildProcess/child_process_stub.cpp";
	const auto result_1 = test_helper::show_file_lines(file_spec1, 60, 80, msg);
	const auto result_2 = test_helper::show_file_lines(file_spec2, 15, 21, "");
	return result_1 && result_2;
}

utilities_test::test_7::test_7(std::string path) : path_(std::move(path))
{}

bool utilities_test::test_7::test()
{
	const message msg = "Req 6 - support sending TestRequest messages from Client to TestHarness Server";

	const auto file_spec1 = path_ + "/TestClient/MainWindow.xaml.cs";
	const auto file_spec2 = path_ + "/Translater/Translater.h";

	const auto result_1 = test_helper::show_file_lines(file_spec1, 214, 228, msg);
	const auto result_2 = test_helper::show_file_lines(file_spec2, 104, 118, msg);

	logger_provider::get_logger().log(debug, "This is done in GUI with the help of Execute test button");

	return result_1 && result_2;
}

utilities_test::test_8::test_8(std::string path) : path_(std::move(path))
{
}

bool utilities_test::test_8::test()
{
	const message msg = "Req 7 - support correctly executing each TestRequest, as a sequence of tests, with each TestRequest running in its own Process Pool child process.";
	Utilities::title(msg);
	const auto file_spec1 = path_ + "/ChildProcess/child_process_stub.cpp";
	test_helper::show_file_lines(file_spec1, 73, 81, ""); 
	logger_provider::get_logger().log(debug, "This demo requirement is compiled as a DLL test library and is send as part of a test request and it is ran within it's own child process");
	return true;
}

utilities_test::test_9::test_9(std::string path) : path_(std::move(path))
{
}

bool utilities_test::test_9::test()
{
	const message msg = "Req 8 - support sending test results, via results messages, from the child process executing the tests to the Client that made the request";
	const auto file_spec1 = path_ + "/ChildProcess/child_process_stub.cpp";
	auto const result_1 = test_helper::show_file_lines(file_spec1, 13, 22, msg);
	logger_provider::get_logger().log(debug, "The test results are send back to the client and populated in the results tab of the GUI. We can open them by double clicking the file name in the list, this is also demonstrated at startup");
	return result_1;
}

utilities_test::test_10::test_10(std::string path) : path_(std::move(path))
{
}

bool utilities_test::test_10::test()
{
	const message msg = "Req 9 - demonstrate correct test operations for two or more concurrent clients"; 
	logger_provider::get_logger().log(debug, "At startup two GUI clients are spawned and each sends a test request for execution and is executed in parallel");
	return true;
}

bool utilities_test::test_11::test()
{
	const message msg = "Req 10 - All these tests are being build as a dll and send to test harness process pool as test request, which is executed in this child process";
	const auto file_spec1 = path_ + "/DemoRequirements/demo_requirements_test_code.cpp";
	auto const result_1 = test_helper::show_file_lines(file_spec1, 21, 41, msg);
	return result_1;
}

utilities_test::test_11::test_11(std::string path) : path_(std::move(path))
{
}



