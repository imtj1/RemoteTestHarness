/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for test_executive, a class which the class which executes each test using test executor
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* <memory>
* <vector>
* "test_item.h"
* "../Utilities/logger.h"
* "test_result_object.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : Oct 27 2018
* - first release
*   ver 2.0 : Oct 27 2018
*  - meeting new requirements
*/
#pragma once
#include <memory>
#include <vector>
#include "test_item.h"
#include "../Utilities/logger.h"
#include "test_result_object.h"

class test_executive
{
using tests = std::vector<test_item>;
public:
	test_result_object do_tests();
	void register_test(std::shared_ptr<test_interface> test_p, const std::string & test_name);
	void register_tests(std::vector<test_item> test_items);
	void register_test(const test_item& test_item);
	void clear_tests();
	static void show_test_results(test_result_object);
private:
	tests tests_container_{};
};
