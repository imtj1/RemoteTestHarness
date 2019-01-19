#pragma once
/*
 * Package Operations:
 * -------------------
 * This package hosts all the processes and connects the client with the child processes, each test requests flows through the process pool host and is forwarded to a child process
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

class process_pool_host
{
public:
	static void instantiate_process_pool_host(std::string host_name);
};

