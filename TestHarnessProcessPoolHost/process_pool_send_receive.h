#pragma once
/*
 * Package Operations:
 * -------------------
 * This package provides the send and receive functions for for the process pool host. These functions are usually run on different threads for non blocking behaviour
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  "../CppCommWithFileXfer/MsgPassingComm/Comm.h"
*  "../CppCommWithFileXfer/Message/Message.h"
*  "../TestRequest/TestRequest.h"
* Maintenance History:
* -------------------
* ver 1.0 : Nov 11 2018
* - first release
*/
#include "../CppCommWithFileXfer/MsgPassingComm/Comm.h"
#include "../CppCommWithFileXfer/Message/Message.h"
#include "../TestRequest/TestRequest.h"

using namespace MsgPassingCommunication;
using namespace Testing;

using test_request_queue = BlockingQueue<Message>;
using ready_queue = BlockingQueue<Message>;
class process_pool_send_receive
{
public:
	static void get_messages(Comm& comm, test_request_queue& test_request_queue, ready_queue& ready_queue, std::atomic<int> &client_register_count);
	static void send_messages(Comm& comm, test_request_queue& test_request_queue, ready_queue& ready_queue, std::string dll_location);
};

