#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for test_item, a class which contains he pointer to each test and the test name
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* <memory>
* <vector>
* "test_interface.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : Oct 27 2018
* - first release
*   ver 2.0 : Oct 27 2018
*  - meeting new requirements
*/
#include <memory>
#include <vector>
#include "test_interface.h"

struct test_item
{
	std::shared_ptr<test_interface> test_p;
	std::string test_name;
};

