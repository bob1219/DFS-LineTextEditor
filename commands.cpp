// standard library
#include <string>

// boost
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

// header
#include "function.h"
#include "Files.h"
#include "File.h"

// using
using namespace dfs_lte;
using namespace std;
using namespace boost;

void dfs_lte::command::o(Files& files, const wstring& fileno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		File file(files.get(fileno));
		file.open(file.getFilename());
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno");
	}
}

void dfs_lte::command::o(Files& files, const wstring& fileno_s, const wstring& filename)
{
	if(fileno_s == L"-n")
	{
		File file(files.add());
		file.open(filename);
	}
	else
	{
		try
		{
			unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
			File file(files.get(fileno));
			file.open(filename);
		}
		catch(bad_lexical_cast)
		{
			throw dfs_lte::exception(L"invalid fileno");
		}
	}
}

void dfs_lte::command::cl(Files& files, const wstring& fileno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		files.close(fileno);
	}
	catch(bad_lexical_cast)
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
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		unsigned int lineno = lexical_cast<unsigned int>(lineno_s);
		files.get(fileno).edit(lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno or lineno");
	}
}

void dfs_lte::command::a(Files& files, const wstring& fileno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		files.get(fileno).append();
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno");
	}
}

void dfs_lte::command::i(Files& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		unsigned int lineno = lexical_cast<unsigned int>(lineno_s);
		files.get(fileno).insert(lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno or lineno");
	}
}

void dfs_lte::command::cp(Files& files, const wstring& fileno_s, const wstring& from_lineno_s, const wstring& to_lineno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		unsigned int from_lineno = lexical_cast<unsigned int>(from_lineno_s);
		unsigned int to_lineno = lexical_cast<unsigned int>(to_lineno_s);
		files.get(fileno).copy(from_lineno, to_lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno or lineno");
	}
}

void dfs_lte::command::w(const Files& files, const wstring& fileno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		files.get(fileno).write();
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno");
	}
}

void dfs_lte::command::w(const Files& files, const wstring& fileno_s, const wstring& filename)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		files.get(fileno).write(filename);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno");
	}
}

void dfs_lte::command::as(Files& files, const wstring& fileno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		file.get(fileno).appends();
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno");
	}
}

void dfs_lte::command::r(Files& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		unsigned int lineno = lexical_cast<unsigned int>(lineno_s);
		files.get(fileno).remove(lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno or lineno");
	}
}

void dfs_lte::command::l(const Files& files, const wstring& fileno_s)
{
	for(wstring line: lines)
	{
		static unsigned int i = 1;
		wcout << wformat(L"%1%:\t%2%") % i % line << endl;
		++i;
	}
}
