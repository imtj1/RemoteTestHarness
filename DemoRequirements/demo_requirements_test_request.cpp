/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for demo_requirements_test_request.
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "demo_requirements_test_request.h"
*  "demo_requirements_test_provider.h"
*  "../Utilities/logger_provider.h"
*/
#include "pch.h"
#include "demo_requirements_test_request.h"
#include "demo_requirements_test_provider.h"
#include "../Utilities/logger_provider.h"

std::string test_name = "demo_requirements_test";
std::string test_author = "Demo@Tony";

void demo_requirements_test_request::accept_test_resource(logger* logger)
{
	logger_provider::register_logger(*logger);
}

std::vector<test_item> demo_requirements_test_request::tests()
{
	return demo_requirements_test_provider::get_all_demo_requirement_tests();
}

std::string demo_requirements_test_request::get_test_request_message()
{
	return test_name;
}

std::string demo_requirements_test_request::get_test_author()
{
	return test_author;
}

__declspec(dllexport) dll_test_request* get_tests()
{
	return new demo_requirements_test_request;
}
