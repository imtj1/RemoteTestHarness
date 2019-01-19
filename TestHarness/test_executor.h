#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for test_executor, a class which execute test in a try catch block
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* "test_item.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : Oct 27 2018
* - first release
*   ver 2.0 : Oct 27 2018
*  - meeting new requirements
*/
#include "test_item.h"

class test_executor
{
public:
	static bool execute(test_item test_item);
private:
	static void check(const bool result, std::string test_name);
};

