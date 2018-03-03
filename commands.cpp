// standard library
#include <string>

// boost
#include <boost/lexical_cast.hpp>

// header
#include "function.h"
#include "class.h"

// using
using namespace dfs_lte;
using namespace std;
using namespace boost;

void dfs_lte::command::o(Files& files, const wstring& fileno_s)
{
	try
	{
		int fileno = lexical_cast<int>(fileno_s);
		File file = files.get(fileno);
		file.open(file.getFilename());
	}
	catch(bad_lexical_cast& e)
	{
		throw dfs_lte::exception(L"invalid fileno");
	}
}

void dfs_lte::command::o(Files& files, const wstring& fileno_s, const wstring& filename)
{
	if(fileno_s == L"-n")
	{
		File file = files.add();
		file.open(filename);
	}
	else
	{
		try
		{
			int fileno = lexical_cast<int>(fileno_s);
			File file = files.get(fileno);
			file.open(filename);
		}
		catch(bad_lexical_cast& e)
		{
			throw dfs_lte::exception(L"invalid fileno");
		}
	}
}

void dfs_lte::command::cl(Files& files, const wstring& fileno_s)
{
	try
	{
		int fileno = lexical_cast<int>(fileno_s);
		files.close(fileno);
	}
	catch(bad_lexical_cast& e)
	{
		throw dfs_lte::exception(L"invalid fileno");
	}
}

void dfs_lte::command::f(const Files& files)
{
	files.list();
}

void dfs_lte::command::e(Files& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		int fileno = lexical_cast<int>(fileno_s);
		int lineno = lexical_cast<int>(lineno_s);
		files.get(fileno).edit(lineno);
	}
	catch(bad_lexical_cast& e)
	{
		throw dfs_lte::exception(L"invalid fileno or lineno");
	}
}

void dfs_lte::command::a(Files& files, const wstring& fileno_s)
{
	try
	{
		int fileno = lexical_cast<int>(fileno_s);
		files.get(fileno).append();
	}
	catch(bad_lexical_cast& e)
	{
		throw dfs_lte::exception(L"invalid fileno");
	}
}

void dfs_lte::command::i(Files& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		int fileno = lexical_cast<int>(fileno_s);
		int lineno = lexical_cast<int>(lineno_s);
		files.get(fileno).insert(lineno);
	}
	catch(bad_lexical_cast& e)
	{
		throw dfs_lte::exception(L"invalid fileno or lineno");
	}
}
