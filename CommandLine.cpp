// CommandLine.cpp
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a source file in DFS-LineTextEditor project.
// This file and DFS-LineTextEditor project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <string>
#include <iostream>
#include <vector>

// boost
#include <boost/format.hpp>

// header
#include "function.h"
#include "exception.h"
#include "File.h"

// using
using namespace dfs_lte;
using namespace std;
using namespace boost;

[[noreturn]] void dfs_lte::CommandLine(const File& file)
{
	vector<File> files;
	files.push_back(file);

	while(true)
	{
		wstring command;

		wcout << L'>';
		getline(wcin, command);

		if(command == L"")
			continue;

		try
		{
			CommandProcess(files, command);
		}
		catch(dfs_lte::exception& e)
		{
			wcerr << wformat{L"error: %1%."} % e.getMessage() << endl;
		}

		wcout << endl;
	}
}
