#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the header for all Dll executor, which loads all dll from a directory and executes them.
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* #include <string>
* <vector>
* "../TestRequest/TestRequest.h"
* "test_results.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : Oct 27 2018
*  - first release
*  ver 2.0 : Oct 27 2018
*  - meeting new requirements
*/
#include <string>
#include <vector>
#include "../TestRequest/TestRequest.h"
#include "test_results.h"

class test_request_executor
{
public:
	static test_results execute_test_request(Testing::TestRequest, std::string dll_location);
};

