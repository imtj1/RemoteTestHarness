#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for test request which exposes the necessary functions for a dll.
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* <vector>
* "../TestHarness/test_item.h"
* "../Utilities/logger.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : Oct 27 2018
* - first release
*   ver 2.0 : Oct 27 2018
*  - meeting new requirements
*/
#include <vector>
#include "../TestHarness/test_item.h"
#include "../Utilities/logger.h"

class dll_test_request {  // NOLINT
public:
	virtual ~dll_test_request() = default;
	virtual void accept_test_resource(logger*) = 0;
	virtual std::vector<test_item> tests() = 0;
	virtual std::string get_test_request_message() = 0;
	virtual std::string get_test_author() = 0;
};
extern "C" {
	__declspec(dllexport) dll_test_request* get_tests();
}
