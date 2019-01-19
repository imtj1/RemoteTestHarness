/*
* Package Operations:
* -------------------
* This package contains the declaration for all code utilities tests
*
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
*  Platform:    Apple Mac Book Air Intel core i5 Parallels VM 
*  version: 1.0
*  Required Files:
*  -------------------
*   CodeUtilities.h
*   code_utilities_test_interface.h
*   *  Maintenance History:
*  -------------------
*  ver 1.0 : 11 Nov 2018
* - first release
 */
#pragma once
#include "code_utilities.h"
#include "code_utilities_test_interface.h"

/*
 *  Test Description:
 *    Tests the instantiation of process command line objects
 *    Test procedure
 *    checks if the instantiated values are correct
 */
class test_code_utilities_instantiation : public code_utilities_test_interface
{
public:
	static std::string test_name();

	explicit test_code_utilities_instantiation(Utilities::ProcessCmdLine& pc_cmd_line)
		: code_utilities_test_interface(pc_cmd_line)
	{
	}

	bool test() override;
};

/*
 *  Test Description:
 *    Tests the change of path in process command line 
 *    Test procedure
 *    checks if the changed value is correct
 */
class test_code_utilities_change_path : public code_utilities_test_interface
{
public:
	static std::string test_name();

	explicit test_code_utilities_change_path(Utilities::ProcessCmdLine& pc_cmd_line)
		: code_utilities_test_interface(pc_cmd_line)
	{
	}

	bool test() override;
};

/*
 *  Test Description:
 *    Tests the change of pattern in process command line
 *    Test procedure
 *    checks if the changed value is correct
 */
class test_code_utilities_change_pattern : public code_utilities_test_interface
{
public:
	static std::string test_name();

	explicit test_code_utilities_change_pattern(Utilities::ProcessCmdLine& pc_cmd_line)
		: code_utilities_test_interface(pc_cmd_line)
	{
	}

	bool test() override;
};

/*
 *  Test Description:
 *    Tests the change of option in process command line
 *    Test procedure
 *    checks if the changed value is correct
 */
class test_code_utilities_change_option : public code_utilities_test_interface
{
public:
	static std::string test_name();

	explicit test_code_utilities_change_option(Utilities::ProcessCmdLine& pc_cmd_line)
		: code_utilities_test_interface(pc_cmd_line)
	{
	}

	bool test() override;
};

/*
 *  Test Description:
 *    Tests the change of max in process command line
 *    Test procedure
 *    checks if the changed value is correct
 */
class test_code_utilities_change_max_item : public code_utilities_test_interface
{
public:
	static std::string test_name();

	explicit test_code_utilities_change_max_item(Utilities::ProcessCmdLine& pc_cmd_line)
		: code_utilities_test_interface(pc_cmd_line)
	{
	}

	bool test() override;
};

/*
 *  Test Description:
 *    Tests the if the test error is false if the right values are given
 *    Test procedure
 *    checks if the value is correct
 */
class test_code_utilities_parse_error_false_test : public code_utilities_test_interface
{
public:
	static std::string test_name();

	explicit test_code_utilities_parse_error_false_test(Utilities::ProcessCmdLine& pc_cmd_line)
		: code_utilities_test_interface(pc_cmd_line)
	{
	}

	bool test() override;
};

/*
 *  Test Description:
 *    Tests the if the test error is true if the wrong values or less than 2 args are given
 *    Test procedure
 *    checks if the value is correct
 */
class test_code_utilities_parse_error_true_test : public test_interface
{
public:
	static std::string test_name();
	bool test() override;
};

/*
 *  Test Description:
 *    Tests the if the convertor converts value to string value
 *    Test procedure
 *    checks if the return value is correct
 */
class converter_to_string_test : public test_interface
{
public:
	static std::string test_name();
	bool test() override;
};

/*
 *  Test Description:
 *    Tests the if the convertor converts string to value
 *    Test procedure
 *    checks if the return value is correct
 */
class converter_to_value_test : public test_interface
{
public:
	static std::string test_name();
	bool test() override;
};

/*
 *  Test Description:
 *    Tests the if the box wraps the value correctly
 *    Test procedure
 *    checks if the return value is correct
 */
class box_double_value_test : public test_interface
{
public:
	static std::string test_name();
	bool test() override;
};

/*
 *  Test Description:
 *    Tests the if the persist factory corectly converts to xml
 *    Test procedure
 *    checks if the return value is correct
 */
class persist_factory_xml_test : public test_interface
{
public:
	static std::string test_name();
	bool test() override;
};
