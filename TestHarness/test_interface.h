#pragma once
/*
 * Package Operations:
 * -------------------
 * This package contains the declaration test_interface which should be implemented by all tests in the application. Contains a test() method to do test for each test case
 * ---------------
 * @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
*  Required Files:
*  -------------------
*   Maintenance History:
*   -------------------
*   ver 1.0 : Oct 27 2018
*/
struct test_interface {
	virtual bool test() = 0;
	virtual ~test_interface() = default;
};