// CommandProcess.cpp
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a source file in DFS-LineTextEditor project.
// This file and DFS-LineTextEditor project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <vector>
#include <string>
#include <cstdlib>

// header
#include "function.h"
#include "File.h"
#include "wtokenizer.h"
#include "exception.h"

// using
using namespace dfs_lte;
using namespace std;

void dfs_lte::CommandProcess(vector<File>& files, vector<wstring>& cpBuf const wstring& command)
{
	// Tokenize
	vector<wstring> tokens;
	wtokenizer Tokenizer{command, wseparator{L'\\', L' ', L'\''}};
	for(wstring token: Tokenizer)
		tokens.push_back(token);

	auto arg_error = [](){ throw dfs_lte::exception{L"few or many arguments"}; };

	if(tokens.at(0) == L"o")
	{
		if(tokens.size() == 2)
			command::o(files, tokens.at(1));
		else if(tokens.size() == 3)
			command::o(files, tokens.at(1), tokens.at(2));
		else arg_error();
	}
	else if(tokens.at(0) == L"cl")
	{
		if(tokens.size() != 2)
			arg_error();
		command::cl(files, tokens.at(1));
	}
	else if(tokens.at(0) == L"f")
	{
		if(tokens.size() != 1)
			arg_error();
		command::f(files);
	}
	else if(tokens.at(0) == L"e")
	{
		if(tokens.at(1) == L"-c")
		{
			if(tokens.size() != 5)
				arg_error();
			command::e(files, tokens.at(2), tokens.at(3), tokens.at(4), cpBuf);
		}
		else
		{
			if(tokens.size() != 3)
				arg_error();
			command::e(files, tokens.at(1), tokens.at(2));
		}
	}
	else if(tokens.at(0) == L"a")
	{
		if(tokens.at(1) == L"-c")
		{
			if(tokens.size() != 4)
				arg_error();
			command::a(files, tokens.at(2), tokens.at(3), cpBuf);
		}
		else
		{
			if(tokens.size() != 2)
				arg_error();
			command::a(files, tokens.at(1));
		}
	}
	else if(tokens.at(0) == L"i")
	{
		if(tokens.at(1) == L"-c")
		{
			if(tokens.size() != 5)
				arg_error();
			command::i(files, tokens.at(2), tokens.at(3), tokens.at(4), cpBuf);
		}
		else
		{
			if(tokens.size() != 3)
				arg_error();
			command::i(files, tokens.at(1), tokens.at(2));
		}
	}
	else if(tokens.at(0) == L"cp")
	{
		if(tokens.size() != 4)
			arg_error();
		command::cp(files, tokens.at(1), tokens.at(2), tokens.at(3), cpBuf);
	}
	else if(tokens.at(0) == L"w")
	{
		if(tokens.size() == 2)
			command::w(files, tokens.at(1));
		else if(tokens.size() == 3)
			command::w(files, tokens.at(1), tokens.at(2));
		else arg_error();
	}
	else if(tokens.at(0) == L"as")
	{
		if(tokens.size() != 2)
			arg_error();
		command::as(files, tokens.at(1));
	}
	else if(tokens.at(0) == L"r")
	{
		if(tokens.size() != 3)
			arg_error();
		command::r(files, tokens.at(1), tokens.at(2));
	}
	else if(tokens.at(0) == L"l")
	{
		if(tokens.size() == 2)
			command::l(files, tokens.at(1));
		else if(tokens.size() == 3)
			command::l(files, tokens.at(1), tokens.at(2));
		else if(tokens.size() == 4)
			command::l(files, tokens.at(1), tokens.at(2), tokens.at(3));
		else arg_error();
	}
	else if(tokens.at(0) == L"fcl")
	{
		if(tokens.size() != 2)
			arg_error();
		command::fcl(files, tokens.at(1));
	}
	else if(tokens.at(0) == L"q")
	{
		if(!files.getAllSaved())
			throw dfs_lte::exception{L"please save all files"};
		exit(EXIT_SUCCESS);
	}
	else if(tokens.at(0) == L"fq")
		exit(EXIT_SUCCESS);
	else throw dfs_lte::exception{L"unknown command"};
}
