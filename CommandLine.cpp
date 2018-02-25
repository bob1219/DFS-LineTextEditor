// standard library
#include <string>
#include <iostream>

// header
#include "function.h"
#include "class.h"

// using
using namespace dfs_lte;
using namespace std;

[[noreturn]] void dfs_lte::CommandLine(const Files& files)
{
	while(true)
	{
		wstring command;

		wcout << L'>';
		getline(wcin, command);

		CommandProcess(files, command);

		wcout << endl;
	}
}
