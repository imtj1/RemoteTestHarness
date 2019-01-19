/*
* Package Operations:
* -------------------
* This package contains the header for code_utilities_test_provider
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*   "../TestHarness/test_item.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : 11 Nov 2018
* - first release
 */

#pragma once
#include "../TestHarness/test_item.h"

class code_utilities_test_provider
{
public:
	static std::vector<test_item> get_all_code_utilities_test();
};
