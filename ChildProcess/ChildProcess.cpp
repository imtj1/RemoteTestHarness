// ChildProcess.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
 * Package Operations:
* -------------------
* This package provides the entry point for the child processes
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
 */
#include "pch.h"
#include <iostream>
#include "../Utilities/logger_provider.h"
#include "child_process_stub.h"

int main(const int argc, char** argv)
{
	if (argc != 3)
	{
		std::cout << "Wrong Arguments";
		return 1;
	}
	const std::string child_port_number = argv[1];
	const std::string parent_port_number = argv[2];
	child_process_stub::instantiate_child_process(child_port_number, parent_port_number);
	return 0;
}

