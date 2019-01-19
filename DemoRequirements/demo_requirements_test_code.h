#pragma once
/*
* Package Operations:
* -------------------
* This package contains the declaration for demo requirement tests
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "../Utilities/string_utilities.h"
*  "../Utilities/file_system.h"
*  "../TestHarness/test_interface.h"
*    Maintenance History:
*    -------------------
*    ver 1.0 : 11 Nov 2018
*   - first release
 */

#include "../Utilities/string_utilities.h"
#include "../Utilities/file_system.h"
#include "../TestHarness/test_interface.h"

namespace utilities_test
{
	using path = std::string;
	using message = std::string;
	using line = size_t;
	using file = std::string;
	using files = std::vector<file>;

	class test_1 : public test_interface
	{
		/*
		*  Test Description:
		*    Demonstrates use of C++
		*  Test Procedure:
		*  - Displays C++ files in project directory
		*/
		const std::string path_;
	public:
		explicit test_1(std::string path);

		bool test() override;
	};

	class test_2 : public test_interface
	{
		/*
		*  Test Description:
		*    Demonstrates use of C++ streams
		*  Test Procedure:
		*  - Displays lines of project source code that use iostream.
		*  - To insure that std streams are used for ALL output
		*    requires code inspection.
		*/
	private:
		const std::string path_;
	public:
		explicit test_2(std::string path);

		bool test() override;
	};

	class test_3 : public test_interface
	{
		/*
		*  Test Description:
		*    Demonstrates use of C++ new and delete operators
		*  Test Procedure:
		*  - Displays lines of project source code that use new
		*    and std::shared-ptr which will use delete when out
		*    of scope.
		*  - To insure no use of malloc or free requires code
		*    inspection or more advanced test tool with text
		*    finder capability.
		*/
		const std::string path_;
	public:
		explicit test_3(std::string path);

		bool test() override;
	};

	class test_4 : public test_interface
	{
		/*
		*  Test for loading all test libraries(dll) in a specific location and 
		*  execute it using the executor package
		*/
		const std::string path_;
	public:
		explicit test_4(std::string path);

		bool test() override;
	};

	class test_5 : public test_interface
	{
		/*
		 *Test for checking whether logger executor and loader packages are
		 *provided
		*/
		const std::string path_;
	public:
		explicit test_5(std::string path);

		bool test() override;
	};

	class test_6 : public test_interface
	{
		/*
		* Test for checking whether the logger package can be used
		* to write to different streams. Also check whether the different loggers are used for different
		* Test requests(dll)
		*/
		const std::string path_;
	public:
		explicit test_6(std::string path);

		bool test() override;
	};


	class test_7 : public test_interface
	{
		/*
		*  Showing lines of code which proves each test request is given 
		*  different instance of the logger.
		*/
		const std::string path_;
	public:
		explicit test_7(std::string path);

		bool test() override;
	};

	class test_8 : public test_interface
	{
		/*
		* Showing all test cases included in the demo 
		* requirements
		*/
		const std::string path_;
	public:
		explicit test_8(std::string path);

		bool test() override;
	};

	class test_9 : public test_interface
	{
		/*
		* Showing all test cases included in the demo
		* requirements
		*/
		const std::string path_;
	public:
		explicit test_9(std::string path);

		bool test() override;
	};

	class test_10 : public test_interface
	{
		/*
		* Showing all test cases included in the demo
		* requirements
		*/
		const std::string path_;
	public:
		explicit test_10(std::string path);

		bool test() override;
	};

	class test_11 : public test_interface
	{
		/*
		* Showing all test cases included in the demo
		* requirements
		*/
		const std::string path_;
	public:
		explicit test_11(std::string path);

		bool test() override;
	};
}
