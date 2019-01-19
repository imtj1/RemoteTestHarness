/*
* Package Operations:
* -------------------
* This package implements the function for code_utilities_test_request.
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "code_utilities_test_request.h"
*  "../CodeUtilities/code_utilities_test_provider.h"
*  "../Utilities/logger.h"
*  "../Utilities/logger_provider.h"
 */
#include "pch.h"
#include "code_utilities_test_request.h"
#include "../CodeUtilities/code_utilities_test_provider.h"
#include "../Utilities/logger.h"
#include "../Utilities/logger_provider.h"

std::string test_name = "code_utilities_tests";
std::string test_author = "codeutilities@tony";


void code_utilities_test_request::accept_test_resource(logger* logger)
{
	logger_provider::register_logger(*logger);

}

std::vector<test_item> code_utilities_test_request::tests()
{
	return code_utilities_test_provider::get_all_code_utilities_test();
}

std::string code_utilities_test_request::get_test_request_message()
{
	return test_name;
}

std::string code_utilities_test_request::get_test_author()
{
	return test_author;
}

__declspec(dllexport) dll_test_request* get_tests()
{
	return new code_utilities_test_request;
}
