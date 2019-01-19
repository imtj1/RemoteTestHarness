#pragma once
/*
* Package Operations:
* -------------------
* This package contains the code utilities implementation for test_interface
*
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*  ../TestHarness/test_interface.h
*  code_utilities.h
*  *  Maintenance History:
*  -------------------
*  ver 1.0 : 11 Nov 2018
* - first release
 */

#include "../TestHarness/test_interface.h"
#include "code_utilities.h"

// <------Inheriting test interface for use with code utilities test
class code_utilities_test_interface : public test_interface
{
public:
	explicit code_utilities_test_interface(Utilities::ProcessCmdLine& pc_cmd_line) : process_cmd_line(pc_cmd_line)
	{
	}

	Utilities::ProcessCmdLine process_cmd_line;
};
