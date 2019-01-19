/*
 * Package Operations:
 * -------------------
 * This package contains the declaration for useful namespaces
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* <string>
* <vector>
* Maintenance History:
* -------------------
* ver 1.0 : Oct 27 2018
* - first release
* ver 2.0 : Oct 27 2018
* - meeting new requirements
*/
#pragma once
#include <string>
#include <vector>

namespace common_types {
	using path = std::string;
	using message = std::string;
	using line = size_t;
	using file = std::string;
	using files = std::vector<file>;
}
