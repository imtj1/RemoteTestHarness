/*
 *  Package Operations:
* -------------------
 * This package hosts all the processes and connects the client with the child processes, each test requests flows through the process pool host and is forwarded to a child process
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
 */
#include "pch.h"
#include "process_pool_host.h"
#include <iostream>
#include <thread>
#include "../Process/Process/process_pool.h"
#include "../CppCommWithFileXfer/MsgPassingComm/Comm.h"
#include "process_pool_send_receive.h"
#include "../Utilities/logger_provider.h"

using namespace MsgPassingCommunication;

using test_request_queue = BlockingQueue<Message>;
using ready_queue = BlockingQueue<Message>;
void process_pool_host::instantiate_process_pool_host(const std::string host_name)
{
	std::atomic<int> client_count = 0;
	ready_queue ready_queue;
	test_request_queue request_queue;
	const auto mother_port_number = 8081;
	const auto child_process_executable_location = "../Debug/ChildProcess.exe";
	const auto host_save_path_location = "../MotherReceiveSendFile";

	const EndPoint test_harness_mother("localhost", mother_port_number);
	Comm comm(test_harness_mother, host_name);
	comm.start();

	const auto save_path = comm.setSaveFilePath(host_save_path_location);
	logger_provider::get_logger().log(debug, "saving files to \"" + save_path + "\"");
	
	process_pool::create(2, child_process_executable_location, mother_port_number);

	std::function<void()> get_message_function = [&]() { process_pool_send_receive::get_messages(comm, request_queue, ready_queue, std::ref(client_count)); };
	std::thread get_message_thread(get_message_function);

	std::function<void()> send_message_function = [&]() { process_pool_send_receive::send_messages(comm, request_queue, ready_queue, host_save_path_location); };
	std::thread send_message_thread(send_message_function);

	get_message_thread.join();
	send_message_thread.join();
	logger_provider::get_logger().log(debug, "Process exited, Press any key to exit");
	comm.stop();
}
