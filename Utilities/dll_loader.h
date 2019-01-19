#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the header for dll_loader. It is used to extract test request from a dll.
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "demo_requirements_test_request.h"
*  "demo_requirements_test_provider.h"
*  "../Utilities/logger_provider.h"
*   Maintenance History:
*   -------------------
*   ver 1.0 : 11 Nov 2018
*  - first release
*/
#include <vector>
#include <windows.h>
#include "../TestHarness/dll_test_request.h"


class dll_loader
{
public:
	dll_test_request* load_dll_test_request(const std::string& dll);
	static std::vector<std::string> get_all_dll_paths(const std::string&);
	void clear() const;
private:
	HMODULE h_mod_ = nullptr;
};
