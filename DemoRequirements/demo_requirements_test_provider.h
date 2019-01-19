/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for demo_requirements_test_provider, a class which provides all test cases related to demo requirements
 * ---------------
 * @author : Tony Joseph
 * Required Files:
*  -------------------
*  "../TestHarness/test_item.h"
*  "../TestHarness/test_executive.h"
 *   Maintenance History:
 *   -------------------
 *   ver 1.0 : 11 Nov 2018
 *  - first release
 */
#pragma once
#include "../TestHarness/test_item.h"
#include "../TestHarness/test_executive.h"

class demo_requirements_test_provider
{
public:
	static std::vector<test_item> get_all_demo_requirement_tests();
};

