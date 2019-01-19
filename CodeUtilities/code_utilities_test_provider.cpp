/*
* Package Operations:
* -------------------
* This package contains the test provider for code utilities package.
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* "code_utilities_test_provider.h"
* "code_utilities_test_code.h"
* "../Utilities/string_utilities.h"
* "../TestHarness/dll_test_request.h"
 */

#include "pch.h"
#include "code_utilities_test_provider.h"
#include "code_utilities_test_code.h"
#include "../Utilities/string_utilities.h"
#include "../TestHarness/dll_test_request.h"

// -----< returns all the set of tests related to demo requirements
std::vector<test_item> code_utilities_test_provider::get_all_code_utilities_test()
{
	Utilities::Title("Testing Code Utilities");
	std::vector<test_item> list_of_code_utilities_tests;
	char arg0[] = "5";
	char arg1[] = "C:desktop";
	char arg2[] = { "/p" };
	char arg3[] = "*.cpp";
	char arg4[] = "10";
	char* argv1[] = { &arg0[0], &arg1[0], &arg2[0], &arg3[0], &arg4[0] };
	Utilities::ProcessCmdLine process_command_line(5, argv1);
	test_item test_item1{};
	test_item1.test_p = std::static_pointer_cast<test_interface>(
		std::make_shared<test_code_utilities_instantiation>(process_command_line));
	test_item1.test_name = test_code_utilities_instantiation::test_name();
	list_of_code_utilities_tests.push_back(test_item1);

	test_item test_item2{};
	test_item2.test_p = std::static_pointer_cast<test_interface>(
		std::make_shared<test_code_utilities_change_path>(process_command_line));
	test_item2.test_name = test_code_utilities_change_path::test_name();
	list_of_code_utilities_tests.push_back(test_item2);

	test_item test_item3{};
	test_item3.test_p = std::static_pointer_cast<test_interface>(
		std::make_shared<test_code_utilities_change_option>(process_command_line));
	test_item3.test_name = test_code_utilities_change_option::test_name();
	list_of_code_utilities_tests.push_back(test_item3);

	test_item test_item4{};
	test_item4.test_p = std::static_pointer_cast<test_interface>(
		std::make_shared<test_code_utilities_change_pattern>(process_command_line));
	test_item4.test_name = test_code_utilities_change_pattern::test_name();
	list_of_code_utilities_tests.push_back(test_item4);

	test_item test_item5{};
	test_item5.test_p = std::static_pointer_cast<test_interface>(
		std::make_shared<test_code_utilities_change_max_item>(process_command_line));
	test_item5.test_name = test_code_utilities_change_max_item::test_name();
	list_of_code_utilities_tests.push_back(test_item5);

	test_item test_item6{};
	test_item6.test_p = std::static_pointer_cast<test_interface>(
		std::make_shared<test_code_utilities_parse_error_false_test>(process_command_line));
	test_item6.test_name = test_code_utilities_parse_error_false_test::test_name();
	list_of_code_utilities_tests.push_back(test_item6);

	test_item test_item7{};
	test_item7.test_p = std::static_pointer_cast<test_interface>(
		std::make_shared<test_code_utilities_parse_error_true_test>());
	test_item7.test_name = test_code_utilities_parse_error_true_test::test_name();
	list_of_code_utilities_tests.push_back(test_item7);

	test_item test_item8{};
	test_item8.test_p = std::static_pointer_cast<test_interface>(std::make_shared<converter_to_string_test>());
	test_item8.test_name = converter_to_string_test::test_name();
	list_of_code_utilities_tests.push_back(test_item8);

	test_item test_item9{};
	test_item9.test_p = std::static_pointer_cast<test_interface>(std::make_shared<converter_to_value_test>());
	test_item9.test_name = converter_to_value_test::test_name();
	list_of_code_utilities_tests.push_back(test_item9);

	test_item test_item10{};
	test_item10.test_p = std::static_pointer_cast<test_interface>(std::make_shared<box_double_value_test>());
	test_item10.test_name = box_double_value_test::test_name();
	list_of_code_utilities_tests.push_back(test_item10);

	test_item test_item11{};
	test_item11.test_p = std::static_pointer_cast<test_interface>(std::make_shared<persist_factory_xml_test>());
	test_item11.test_name = persist_factory_xml_test::test_name();
	list_of_code_utilities_tests.push_back(test_item11);

	return list_of_code_utilities_tests;
}

