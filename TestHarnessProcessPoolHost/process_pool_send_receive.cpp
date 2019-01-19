/*
 *  Package Operations:
* -------------------
 * This package provides the send and receive functions for for the process pool host. These functions are usually run on different threads for non blocking behaviour
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
 */
#include "pch.h"
#include "process_pool_send_receive.h"
#include "../CppCommWithFileXfer/Message/message_type.h"
#include "../Utilities/logger_provider.h"

Message construct_child_test_request(Message test_request, Message ready_message, const std::string dll_location)
{
	const auto child_port = ready_message.from();
	test_request.to(child_port);
	test_request.attribute(message_type::dll_file_location(), dll_location);
	return test_request;
}

Message construct_child_stop_request(Message stop_request, Message ready_message)
{
	const auto child_port = ready_message.from();
	stop_request.to(child_port);
	return stop_request;
}

void process_pool_send_receive::send_messages(Comm& comm, test_request_queue& test_request_queue, ready_queue& ready_queue, const std::string dll_location)
{
	while (true)
	{
		auto test_request = test_request_queue.deQ();
		if (test_request.command() == "stop")
		{
			logger_provider::get_logger().log(debug, comm.name() + " has received stop command, sending stop command to all children");
			while (ready_queue.size() != 0)
			{
				auto ready_message = ready_queue.deQ();
				logger_provider::get_logger().log(debug, comm.name() + " posting stop command to child at "+ ready_message.value(message_type::ready()));
				const auto child_stop_message = construct_child_stop_request(test_request, ready_message);
				comm.postMessage(child_stop_message);
			}
			logger_provider::get_logger().log(debug, comm.name() + " posted stop command to all children, exiting send message thread");
			break;
		}
		auto ready_message = ready_queue.deQ();
		auto child_request_message = construct_child_test_request(test_request, ready_message, dll_location);
		logger_provider::get_logger().log(debug, comm.name() + " sending test request: "+ child_request_message.value(message_type::test_request_name())+" to child at " + ready_message.value(message_type::ready()));
		comm.postMessage(child_request_message);
	}
}

void process_pool_send_receive::get_messages(Comm& comm, test_request_queue& test_request_queue, ready_queue& ready_queue, std::atomic<int> &client_register_count)
{
	while (true)
	{
		auto message = comm.getMessage();
		if (message.containsKey(message_type::file()))
		{
			if (message.contentLength() == 0)
				logger_provider::get_logger().log(debug, comm.name() + " received file \"" + message.file() + "\""+ message.name());
		}
		if (message.containsKey(message_type::test_request()))
		{
			logger_provider::get_logger().log(debug, comm.name() + " has received test request from " + message.name());
			test_request_queue.enQ(message);
		}
		else if (message.containsKey(message_type::ready()))
		{
			logger_provider::get_logger().log(debug, comm.name() + " has received ready message from child at " + message.value(message_type::ready()));
			ready_queue.enQ(message);
		}
		else if (message.containsKey(message_type::register_client()))
		{
			logger_provider::get_logger().log(debug, comm.name() + " has received registration from " + message.value(message_type::register_client()));
			++client_register_count;
		}
		else if (message.containsKey(message_type::client_done()))
		{
			--client_register_count;
			logger_provider::get_logger().log(debug, comm.name() + " has received done message from " + message.value(message_type::client_done()));
			if (client_register_count == 0)
			{
				logger_provider::get_logger().log(debug, comm.name() + " has received done message from all clients, posting stop command to request queue");
				Message stop;
				stop.command("stop");
				test_request_queue.enQ(stop);
				logger_provider::get_logger().log(debug, comm.name() + " exiting receive messages thread");
				break;
			}
		}
	}
}
