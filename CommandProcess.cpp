// standard library
#include <vector>
#include <string>

// header
#include "function.h"
#include "class.h"
#include "type.h"

// using
using namespace dfs_lte;
using namespace std;

void dfs_lte::CommandProcess(const Files& files, const wstring& command)
{
	vector<wstring> tokens;
	wtokenizer Tokenizer(command, wseparator(L" "));
	for(wstring token: Tokenizer)
		tokens.push_back(token);

	if(tokens.at(0) == L"o")
	{
		if(tokens.size() == 2)
			command::o(tokens.at(1));
		else if(tokens.size() == 2)
			command::o(tokens.at(1), tokens.at(2));
		else
			throw dfs_lte::exception(L"few or many arguments");
	}
	else if(tokens.at(0) == L"cl")
	{
		if(tokens.size() != 2)
			throw dfs_lte::exception(L"few or many arguments");
		command::cl(files, tokens.at(1));
	}
	else if(tokens.at(0) == L"f")
	{
		if(tokens.size() != 1)
			throw dfs_lte::exception(L"few or many arguments");
		command::f(files);
	}
	else if(tokens.at(0) == L"e")
	{
		if(tokens.size() != 3)
			throw dfs_lte::exception(L"few or many arguments");
		command::e(files, tokens.at(1), tokens.at(2));
	}
	else if(tokens.at(0) == L"a")
	{
		if(tokens.size() != 2)
			throw dfs_lte::exception(L"few or many arguments");
		command::a(files, tokens.at(1));
	}
	else if(tokens.at(0) == L"i")
	{
		if(tokens.size() != 3)
			throw dfs_lte::exception(L"few or many arguments");
		command::i(files, tokens.at(1), tokens.at(2));
	}
	else if(tokens.at(0) == L"cp")
	{
		if(tokens.size() != 4)
			throw dfs_lte::exception(L"few or many arguments");
		command::cp(files, tokens.at(1), tokens.at(2), tokens.at(3));
	}
	else if(tokens.at(0) == L"w")
	{
		if(tokens.size() == 2)
			command::w(tokens.at(1));
		else if(tokens.size() == 3)
			command::w(tokens.at(1), tokens.at(2));
		else
			throw dfs_lte::exception(L"few or many arguments");
	}
	else if(tokens.at(0) == L"as")
	{
		if(tokens.size() != 2)
			throw dfs_lte::exception(L"few or many arguments");
		command::as(tokens.at(1));
	}
	else if(tokens.at(0) == L"r")
	{
		if(tokens.size() != 3)
			throw dfs_lte::exception(L"few or many arguments");
		command::r(tokens.at(1), tokens.at(2));
	}
	else throw dfs_lte::exception(L"unknown command");
}
