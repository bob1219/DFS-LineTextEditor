// standard library
#include <string>
#include <iostream>

// boost
#include <boost/format.hpp>

// header
#include "function.h"
#include "Files.h"

// using
using namespace dfs_lte;
using namespace std;
using namespace std;

[[noreturn]] void dfs_lte::CommandLine(const Files& files)
{
	while(true)
	{
		wstring command;

		wcout << L'>';
		getline(wcin, command);

		try
		{
			CommandProcess(files, command);
		}
		catch(dfs_lte::exception& e)
		{
			wcerr << wformat(L"error: %1%.") % e.getMessage() << endl;
		}

		wcout << endl;
	}
}
