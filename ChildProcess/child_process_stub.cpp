/*
 *  Package Operations:
* -------------------
* This package contains the process which is invoked by the harness process pool, this process takes request from mather and sends results to client
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
 */
#include "pch.h"
#include "child_process_stub.h"

void child_process_stub::send_results_to_client(Message file_msg, const EndPoint& end_point_from, const EndPoint& end_point_to, Comm& comm, const test_results test_results)
{
	file_msg.to(end_point_to); 
	logger_provider::get_logger().log(debug,"---------------------------------------------"+end_point_to.port);
	file_msg.from(end_point_from);
	file_msg.attribute(message_type::child_process_results(), test_harness_utils::get_result_string(test_results));
	file_msg.file(test_results.log_file_name);
	logger_provider::get_logger().log(debug, comm.name() + " sending results and log file to client: " + file_msg.name() + " from child process for test request - " + file_msg.value(message_type::test_request_name()));
	comm.postMessage(file_msg);
}

void child_process_stub::send_ready_message_to_mother(Message ready_msg, const EndPoint& end_point_from, const EndPoint& end_point_to, Comm& comm)
{
	ready_msg.attribute(message_type::ready(), std::to_string(end_point_from.port));
	ready_msg.to(end_point_to);
	ready_msg.from(end_point_from);
	ready_msg.name("Child Process ready message");
	comm.postMessage(ready_msg);
	logger_provider::get_logger().log(debug, "sending ready message to test harness process pool host");
}

size_t child_process_stub::get_port_number(const std::string port_number)
{
	std::stringstream string_stream;
	string_stream << port_number;
	size_t port;
	string_stream >> port;
	return port;
}

void child_process_stub::instantiate_child_process(const std::string child_port_number, const std::string parent_port_number)
{
	const auto module_name = "child_process @ " + child_port_number;
	const std::string owner = "childprocess@tony";

	std::ofstream file_stream;
	logger_utils::create_file_stream(module_name, file_stream);
	logger logger;
	logger_utils::configure_logger(&logger, file_stream, owner, debug);

	logger_provider::register_logger(logger);
	const EndPoint parent_process_comm("localhost", get_port_number(parent_port_number));
	const EndPoint child_process_comm("localhost", get_port_number(child_port_number));

	Comm comm(child_process_comm, "child_process");
	comm.start();
	comm.setSendFilePath("./");
	const Message ready_msg;
	send_ready_message_to_mother(ready_msg, child_process_comm, parent_process_comm, comm);
	auto current_process_logger = logger_provider::get_logger();
	while (true)
	{
		auto message = comm.getMessage();

		if (message.command() == "stop") {
			logger_provider::get_logger().log(debug, "Received stop command from process pool host, exiting child process receive thread");
			break;
		}
		if (message.containsKey(message_type::test_request()))
		{
			const auto test_request = TestRequest::fromString(message.value(message_type::test_request()));
			logger_provider::get_logger().log(debug, comm.name() + " received test request: " + message.value(message_type::test_request_name()) + " from test harness process pool");

			const auto dll_location = message.value(message_type::dll_file_location());
			const auto test_results = test_request_executor::execute_test_request(test_request, dll_location);

			logger_provider::register_logger(current_process_logger);
			send_results_to_client(message, child_process_comm, message.from(), comm, test_results);
			send_ready_message_to_mother(ready_msg, child_process_comm, parent_process_comm, comm);
		}
	}

	logger_provider::get_logger().log(debug, "Process exited");
	std::cin.get();
	comm.stop();
}
