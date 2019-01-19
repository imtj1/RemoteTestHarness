/*
 * Package Operations:
 * -------------------
 * This package contains the implementation for dll_loader. It is used to extract test request from a dll.
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "dll_loader.h"
*  "../TestHarness/dll_test_request.h"
*  "logger_provider.h"
*	"file_system.h"
*/
#include "pch.h"
#include "dll_loader.h"
#include "../TestHarness/dll_test_request.h"
#include "logger_provider.h"
#include "../CppCommWithFileXfer/Utilities/FileSystem/FileSystem.h"

std::wstring to_w_string(const std::string& s)
{
	std::wstring w_str;
	for (auto ch : s)
	{
		w_str += wchar_t(ch);
	}
	return w_str;
}

dll_test_request* dll_loader::load_dll_test_request(const std::string& dll)
{
	logger_provider::get_logger().log(debug, "Loading Test Request from Dll : " + dll);
	h_mod_ = LoadLibraryW(to_w_string(dll).c_str());
	if (!h_mod_) {
		logger_provider::get_logger().log(warning, "DLL not loaded");
		return nullptr;
	}
	using dll_p = dll_test_request * (*)();
	const auto test_request_p = reinterpret_cast<dll_p>(GetProcAddress(h_mod_, "get_tests"));
	if (!test_request_p) {
		logger_provider::get_logger().log(warning, "DLL not loaded");
		return nullptr;
	}
	logger_provider::get_logger().log(debug, "Loaded test request from Dll : " + dll);
	const auto tests = test_request_p();
	return tests;
}

std::vector<std::string> dll_loader::get_all_dll_paths(const std::string& path)
{
	auto all_dll_files = FileSystem::Directory::getFiles(path, "*.dll");
	std::vector<std::string> all_m_dll;
	for(auto a_dll : all_dll_files)
	{
		all_m_dll.push_back(path + a_dll);
	}
	return all_m_dll;
}

void dll_loader::clear() const
{
	if (h_mod_) FreeLibrary(h_mod_);
}

