#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for test request executive which takes in a test request and executes all of its tests
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* <vector>
* "../TestHarness/dll_test_request.h"
*   Maintenance History:
*   -------------------
*   ver 1.0 : Oct 27 2018
*   - first release
*   ver 2.0 : Oct 27 2018
*   - meeting new requirements
*/
#include "../TestHarness/dll_test_request.h"
#include "test_result_object.h"

class dll_executive
{
public:
	static test_result_object execute_dll_test_request(dll_test_request*);
};

