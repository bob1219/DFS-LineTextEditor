// standard library
#include <vector>
#include <string>
#include <cstdlib>

// header
#include "function.h"
#include "Files.h"
#include "wtokenizer.h"

// using
using namespace dfs_lte;
using namespace std;

void dfs_lte::CommandProcess(const Files& files, const wstring& command)
{
	vector<wstring> tokens;
	wseparator sep(L'\\', L' ', L'\'');
	wtokenizer Tokenizer(command, sep);
	for(wstring token: Tokenizer)
		tokens.push_back(token);

	auto arg_error = [](){ throw dfs_lte::exception(L"few or many arguments"); };

	if(tokens.at(0) == L"o")
	{
		if(tokens.size() == 2)
			command::o(files, tokens.at(1));
		else if(tokens.size() == 2)
			command::o(files, tokens.at(1), tokens.at(2));
		else
			arg_error();
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
		if(tokens.size() != 3)
			arg_error();
		command::e(files, tokens.at(1), tokens.at(2));
	}
	else if(tokens.at(0) == L"a")
	{
		if(tokens.size() != 2)
			arg_error();
		command::a(files, tokens.at(1));
	}
	else if(tokens.at(0) == L"i")
	{
		if(tokens.size() != 3)
			arg_error();
		command::i(files, tokens.at(1), tokens.at(2));
	}
	else if(tokens.at(0) == L"cp")
	{
		if(tokens.size() != 4)
			arg_error();
		command::cp(files, tokens.at(1), tokens.at(2), tokens.at(3));
	}
	else if(tokens.at(0) == L"w")
	{
		if(tokens.size() == 2)
			command::w(files, tokens.at(1));
		else if(tokens.size() == 3)
			command::w(files, tokens.at(1), tokens.at(2));
		else
			arg_error();
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
		if(tokens.size() != 2)
			arg_error();
		command::l(files, tokens.at(1));
	}
	else if(tokens.at(0) == L"q")
	{
		if(!files.getAllSaved())
			throw dfs_lte::exception(L"please save all files when before quit");
		exit(EXIT_SUCCESS);
	}
	else throw dfs_lte::exception(L"unknown command");
}
