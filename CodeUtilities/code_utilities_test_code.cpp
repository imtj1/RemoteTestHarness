/*
* Package Operations:
* -------------------
* This package contains the implementation for all code utilities tests
*
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  code_utilities_test_code.h
*  ../Utilities/logger_provider.h
 */

#include "pch.h"
#include "code_utilities_test_code.h"
#include "../Utilities/logger_provider.h"

 // <-----Constructing messages and all test requests for code utilities
std::string test_code_utilities_instantiation::test_name()
{
	return "Code Utilities test for instantiating code utilities";
}
std::string test_code_utilities_change_path::test_name() {
	return  "Code Utilities test for changing path";
}
std::string test_code_utilities_change_option::test_name() {
	return  "Code Utilities test for adding option";
}
std::string test_code_utilities_change_pattern::test_name() {
	return  "Code Utilities test for adding pattern";
}
std::string test_code_utilities_change_max_item::test_name() {
	return  "Code Utilities test for changing max items";
}
std::string test_code_utilities_parse_error_true_test::test_name() {
	return
		"Code Utilities test for checking parse error true for number of input arguments < 2";
}
std::string test_code_utilities_parse_error_false_test::test_name() {
	return
		"Code Utilities test for checking parse error false for number of input arguments >= 2";
}
std::string converter_to_string_test::test_name() {
	return
		"Code Utilities test for checking convertor converts value to string";
}
std::string converter_to_value_test::test_name() {
	return
		"Code Utilities test for checking convertor converts string to value";
}
std::string box_double_value_test::test_name() {
	return
		"Code Utilities test for checking boxed value is added and updated";
}
std::string persist_factory_xml_test::test_name() {
	return
		"Code Utilities test for checking persist factory converts to xml";
}

bool test_code_utilities_instantiation::test()
{
	const auto path_correct = process_cmd_line.path() == "C:desktop";
	const auto option_correct = process_cmd_line.hasOption(int('p'));
	const auto max_item_correct = 10 == process_cmd_line.maxItems();
	auto pattern_correct = false;
	for (auto a_pattern : process_cmd_line.patterns())
	{
		pattern_correct = a_pattern == "*.cpp";
	}
	logger_provider::get_logger().log(debug, "Process command line Instantiated with");
	logger_provider::get_logger().log_file_content("\n");
	process_cmd_line.showCmdLine();
	logger_provider::get_logger().log_file_content("\n");
	return max_item_correct && path_correct && option_correct && pattern_correct;
}

bool test_code_utilities_change_path::test()
{
	logger_provider::get_logger().log(debug, "Path initial value");
	process_cmd_line.showPath();
	process_cmd_line.path("c:\\home");
	logger_provider::get_logger().log(debug, "Path changed to");
	process_cmd_line.showPath();
	return process_cmd_line.path() == "c:\\home";
}

bool test_code_utilities_change_pattern::test()
{
	logger_provider::get_logger().log(debug, "Patterns initial value");
	process_cmd_line.showPatterns();
	auto pattern_added = false;
	process_cmd_line.pattern("*.html");
	auto patterns = process_cmd_line.patterns();
	for (auto a_pattern : patterns)
	{
		pattern_added = a_pattern == "*.html";
	}
	logger_provider::get_logger().log(debug, "Pattern changed to");
	process_cmd_line.showPatterns();
	return pattern_added;
}

bool test_code_utilities_change_option::test()
{
	logger_provider::get_logger().log(debug, "Option initial value");
	process_cmd_line.showOptions();
	process_cmd_line.option(int('s'));
	logger_provider::get_logger().log(debug, "Option changed to");
	process_cmd_line.showOptions();
	return process_cmd_line.hasOption(int('s'));
}

bool test_code_utilities_change_max_item::test()
{
	logger_provider::get_logger().log(debug, "Max Items initial value");
	process_cmd_line.showMaxItems();
	process_cmd_line.maxItems(25);
	logger_provider::get_logger().log(debug, "Max Items changed to");
	process_cmd_line.showMaxItems();
	return process_cmd_line.maxItems() == 25;
}

bool test_code_utilities_parse_error_false_test::test()
{
	const auto parse_error = process_cmd_line.parseError();
	return parse_error == false;
}

bool test_code_utilities_parse_error_true_test::test()
{
	logger_provider::get_logger().log(debug, test_name() + " :: Displaying parse error message for number of input arguments < 2");
	Utilities::ProcessCmdLine process_command_line(1, nullptr);
	const auto parse_error = process_command_line.parseError();
	return parse_error;
}

bool converter_to_string_test::test()
{
	const auto test_number_int = 54;
	const auto test_number_double = 54.1234;

	const auto result_for_int_value = Utilities::Converter<int>::toString(test_number_int);
	logger_provider::get_logger().log(debug, "Result for int value : " + result_for_int_value);

	const auto result_for_double_value = Utilities::Converter<double>::toString(test_number_double);
	logger_provider::get_logger().log(debug, "Result for double value : " + result_for_double_value);

	return result_for_int_value == "54" && result_for_double_value == "54.1234";
}

bool converter_to_value_test::test()
{
	const auto test_number_int = "54";
	const auto test_number_double = "54.1234";
	const auto result_for_int = Utilities::Converter<int>::toValue(test_number_int);
	logger_provider::get_logger().log(debug, "Result for int value" + result_for_int);
	const auto result_for_double = Utilities::Converter<double>::toValue(test_number_double);
	logger_provider::get_logger().log(debug, "Result for double value : ");
	logger_provider::get_logger().log(debug, result_for_double);
	return result_for_int == 54 && result_for_double == 54.1234;
}

bool box_double_value_test::test()
{
	Utilities::Box<double> boxed_double = 3.1415927;

	logger_provider::get_logger().log(debug, "Initial value of Boxed double : 3.1415927");
	const auto initial_value_correct = boxed_double == 3.1415927;
	boxed_double = 3.3547;
	logger_provider::get_logger().log(debug, "Value after changing value of Boxed double : 3.3547");
	const auto assigned_value_correct = boxed_double == 3.3547;
	return initial_value_correct && assigned_value_correct;
}

bool persist_factory_xml_test::test()
{
	Utilities::PersistFactory<std::string> name = std::string("Tony");
	name.append(" Joseph");
	Utilities::PersistFactory<Utilities::Box<double>> value = Utilities::Box<double>(9.87654);
	const auto is_xml_correct_for_name = name.toXml("name") == "<name>Tony Joseph</name>";
	logger_provider::get_logger().log(debug, "Initial value of xml : " + value.toXml("value"));
	const auto is_xml_correct_for_initial_value = value.toXml("value") == "<value>9.87654</value>";
	value += 3.14159;
	logger_provider::get_logger().log(debug, "Xml after updating value : " + value.toXml("value"));
	const auto is_xml_correct_for_updated_value = value.toXml("value") == "<value>13.0181</value>";
	return is_xml_correct_for_name && is_xml_correct_for_updated_value && is_xml_correct_for_initial_value;
}
