/*
 *  Package Operations:
* -------------------
* This package contains the instantiation of process pool used by test harness to spawn all child processes
* @author : Tony Joseph
* Language:    Visual C++, Visual Studio 2010
* Platform:    Apple Mac Book Air Intel core i5 Parallels VM
* version: 1.0
 */
#include "process_pool.h"
#include "Process.h"
#include "../../Utilities/logger_provider.h"

static CBP callback;
static std::string app_path_g;
static int port_start_g = 0;
static int parent_port_g = 0;
static int number_of_processes_g = 0;

void call_back_func()
{
	Process backup_child_process;
	backup_child_process.title("Child Process " + std::to_string(port_start_g + number_of_processes_g));
	backup_child_process.application(app_path_g);

	const auto cmd_line1 = "/App " + std::to_string(port_start_g + number_of_processes_g) + " " + std::to_string(parent_port_g);
	backup_child_process.commandLine(cmd_line1);
	backup_child_process.setCallBackProcessing(callback);
	backup_child_process.create();
}

void process_pool::create(const int number_of_process, const std::string& app_path, const int parent_port)
{
	parent_port_g = parent_port;
	port_start_g = parent_port + 1;
	app_path_g = app_path;
	number_of_processes_g = number_of_process;
	callback = []()
	{
		call_back_func();
	};

	for (auto count = 1; count <= number_of_process; count++)
	{
		Process child_process;
		child_process.title("Child Process " + std::to_string(count));
		child_process.application(app_path);

		auto cmd_line = "/App " + std::to_string(port_start_g++) + " " + std::to_string(parent_port);
		child_process.commandLine(cmd_line);

		logger_provider::get_logger().log(debug,"Starting process: \"" +app_path + "with this argument: \"" + cmd_line + "\" at port: " + std::to_string(port_start_g));
		child_process.create();
		
		child_process.setCallBackProcessing(callback);
		child_process.registerCallback();
	}

}

	

