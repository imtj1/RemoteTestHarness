/*
 *  Package Operations:
* -------------------
* This package provides the different message attributes which is used within the application
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
 */
#include "message_type.h"

std::string message_type::test_request() { return "TestRequest"; }
std::string message_type::file() { return "sendingFile"; }
std::string message_type::ready() { return "ReadyMessage"; };
std::string message_type::register_client() { return "Register"; }
std::string message_type::client_done() { return "ClientDone"; };
std::string message_type::child_process_results() { return "ChildProcessDone"; }
std::string message_type::dll_file_location() { return "DllFileLocation"; }
std::string message_type::test_request_name() { return "TestRequestName"; }
std::string message_type::client_name() { return "ClientName"; }