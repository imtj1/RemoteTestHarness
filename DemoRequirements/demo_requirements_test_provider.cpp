/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for demo_requirements_test_provider, a class which provides all test cases related to demo requirements
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "pch.h"
*  "demo_requirements_test_provider.h"
*  "demo_requirements_test_code.h"
*/
#include "pch.h"
#include "demo_requirements_test_provider.h"
#include "demo_requirements_test_code.h"

 // -----< returns all sets registered for demo requirements
std::vector<test_item> demo_requirements_test_provider::get_all_demo_requirement_tests()
{
	Utilities::Title("Demonstrating Project #4 Requirements");
	std::vector<test_item> list_of_demo_requirement_tests;
	std::string path = "..";
	const test_item test_1 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_1>(path)), "Test Requirement 1" };
	list_of_demo_requirement_tests.push_back(test_1);
	const test_item test_2 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_2>(path)), "Test Requirement 2" };
	list_of_demo_requirement_tests.push_back(test_2);
	const test_item test_3 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_3>(path)), "Test Requirement 3a" };
	list_of_demo_requirement_tests.push_back(test_3);
	const test_item test_4 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_4>(path)), "Test Requirement 3b" };
	list_of_demo_requirement_tests.push_back(test_4);
	const test_item test_5 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_5>(path)), "Test Requirement 4" };
	list_of_demo_requirement_tests.push_back(test_5);
	const test_item test_6 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_6>(path)), "Test Requirement 5" };
	list_of_demo_requirement_tests.push_back(test_6);
	const test_item test_7 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_7>(path)), "Test Requirement 6" };
	list_of_demo_requirement_tests.push_back(test_7);
	const test_item test_8 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_8>(path)), "Test Requirement 7" };
	list_of_demo_requirement_tests.push_back(test_8);
	const test_item test_9 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_9>(path)), "Test Requirement 8" };
	list_of_demo_requirement_tests.push_back(test_9);
	const test_item test_10 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_10>(path)), "Test Requirement 9" };
	list_of_demo_requirement_tests.push_back(test_10);
	const test_item test_11 = { std::static_pointer_cast<test_interface>(std::make_shared<utilities_test::test_11>(path)), "Test Requirement 10" };
	list_of_demo_requirement_tests.push_back(test_11);
	return list_of_demo_requirement_tests;
}
