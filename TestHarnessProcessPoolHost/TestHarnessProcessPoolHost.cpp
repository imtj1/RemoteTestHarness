// TestHarnessProcessPoolHost.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
 *  Package Operations:
* -------------------
 * This package provides entry point for test harness process pool host
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
 */
#include "pch.h"
#include "process_pool_host.h"
#include "../Utilities/logger_provider.h"
#include "../Logger/logger_utils.h"

int main()
{
	const std::string process_name = "test_harness_process_pool_host";
	std::ofstream file_stream;
	logger_utils::create_file_stream(process_name, file_stream);
	logger logger;
	logger_utils::configure_logger(&logger, file_stream, "tester@2", debug);
	logger_provider::register_logger(logger);

	process_pool_host::instantiate_process_pool_host(process_name);
	return 0;
}