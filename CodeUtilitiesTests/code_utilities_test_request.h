#pragma once
/*
* Package Operations:
* -------------------
* This package contains the header for code_utilities_test_request. This is used to override the test request interface to enable dll operation from the package
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*   ../TestHarness/dll_test_request.h
*  Maintenance History:
*  -------------------
*  ver 1.0 : 11 Nov 2018
* - first release
 */
#include "../TestHarness/dll_test_request.h"

class code_utilities_test_request : public dll_test_request
{
public:
	void accept_test_resource(logger*) override;
	std::vector<test_item> tests() override;
	std::string get_test_request_message() override;
	std::string get_test_author() override;
};

