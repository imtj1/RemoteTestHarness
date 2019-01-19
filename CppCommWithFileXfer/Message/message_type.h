#pragma once
/*
 * Package Operations:
 * -------------------
 * This package provides the different message attributes which is used within the application
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  <string>
* Maintenance History:
* -------------------
* ver 1.0 : Nov 11 2018
* - first release
*/
#include <string>

class message_type
{
public:
	static std::string file();
	static std::string ready();
	static std::string test_request();
	static std::string register_client();
	static std::string client_done();
	static std::string child_process_results();
	static std::string dll_file_location();
	static std::string test_request_name();
	static std::string client_name();
};
