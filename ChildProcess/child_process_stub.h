/*
* Package Operations:
* -------------------
* This package contains the process which is invoked by the harness process pool, this process takes request from mather and sends results to client
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
* "../Utilities/logger_provider.h"
* <fstream>
* "../Logger/logger_utils.h"
* "../TestHarness/test_request_executor.h"
* <cstdio>
* "../CppCommWithFileXfer/Cpp11-BlockingQueue/BlockingQueue.h"
* "../CppCommWithFileXfer/MsgPassingComm/Comm.h"
* "../TestRequest/TestRequest.h"
* "../CppCommWithFileXfer/Message/message_type.h"
* "../TestHarness/test_harness_utils.h"
*  Maintenance History:
*  -------------------
*  ver 1.0 : 11 Nov 2018
* - first release
*/
#pragma once

#include "pch.h"
#include "../Utilities/logger_provider.h"
#include <fstream>
#include "../Logger/logger_utils.h"
#include "../TestHarness/test_request_executor.h"
#include <cstdio>
#include "../CppCommWithFileXfer/Cpp11-BlockingQueue/BlockingQueue.h"
#include "../CppCommWithFileXfer/MsgPassingComm/Comm.h"
#include "../TestRequest/TestRequest.h"
#include "../CppCommWithFileXfer/Message/message_type.h"
#include "../TestHarness/test_harness_utils.h"

using namespace MsgPassingCommunication;
using namespace Testing;
class child_process_stub
{
public:
	static void send_results_to_client(Message file_msg, const EndPoint& end_point_from, const EndPoint& end_point_to, Comm& comm, const test_results test_results);
	static void send_ready_message_to_mother(Message ready_msg, const EndPoint& end_point_from, const EndPoint& end_point_to, Comm& comm);
	static size_t get_port_number(const std::string port_number);
	static void instantiate_child_process(const std::string child_port_number, const std::string parent_port_number);
};

