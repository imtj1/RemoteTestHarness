#include "pch.h"
#include "test_interface.h"
#include "test_executive.h"
#include <iostream>
#include <fstream>
#include "../Utilities/name_spaces.h"
#include "static_test.h"
#include "../Utilities/test_helper.cpp"
#include "../Utilities/file_system.cpp"

class test_passes : public test_interface
{
public:
	bool test() { return true; }
};


class TestReq3 : public test_interface
{
	/*
	*  Test Description:
	*    Demonstrates that tests implement ITest interface
	*  Test Procedure:
	*  - Displays lines of project source code where tests
	*    are defined.
	*/
	const std::string path_;
public:
	TestReq3(const std::string& path) : path_(path) {}
	~TestReq3() { std::cout << "\n  deleting TestReq3"; }
	bool test()
	{
		std::cout << "reached here1111111111111";
		utitls::Message msg = "Req #3 - tests implement ITest interface";
		utitls::Path fileSpec = path_;
		time_util_1::now_time();
		return test_helper::show_file_lines(fileSpec, 1, 3, msg);
	}
};

int main()
{
	logger l;
	std::ostringstream os;
	std::ofstream f;
	// l.set_log_level(warning);
	std::cout << "Hello World!\n";
	f.open("logNew2.txt");
	l.register_stream(f);
	l.register_stream(os);
	l.register_stream(std::cout);
	test_executive ex(l);

	// define a sequence of test items
	// - each test item holds a std::shared_ptr<ITest> to a test instance created on native heap
	//   and a string test name

	test_item test_item1;
	test_item1.test_p = std::static_pointer_cast<test_interface>(std::make_shared<test_passes>());
	test_item1.test_name = "test_always_passes";

	test_item test_item2;
	test_item2.test_p = std::static_pointer_cast<test_interface>(std::make_shared<TestReq3>("../TestHarness/test_interface.h"));
	test_item2.test_name = "test_show file";
	ex.register_test(test_item1);
	ex.register_test(test_item2);
	bool result = ex.do_tests();

	if (result == true)
		std::cout << "\n  all tests passed";
	else
		std::cout << "\n  at least one test failed";

	std::cout << "\n";
	return 0;
}
