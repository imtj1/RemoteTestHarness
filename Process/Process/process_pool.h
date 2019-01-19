#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the instantiation of process pool used by test harness to spawn all child processes
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* <string>
*  Maintenance History:
*  -------------------
*  ver 1.0 : 11 Nov 2018
* - first release
*/
#include <string>

class process_pool
{
public:
	static void create(int number_of_process, const std::string& app_path, int parent_port);
};

