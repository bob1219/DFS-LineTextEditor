// standard library
#include <string>

// boost
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

// header
#include "function.h"
#include "Files.h"
#include "File.h"
#include "exception.h"

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
		File file(files.get(fileno));
		file.edit(lineno);
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
		File file(files.get(fileno));
		file.append();
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
		File file(files.get(fileno));
		file.insert(lineno);
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
		File file(files.get(fileno));
		file.copy(from_lineno, to_lineno);
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
		File file(files.get(fileno));
		file.write();
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
		File file(files.get(fileno));
		file.write(filename);
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
		File file(files.get(fileno));
		file.appends();
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
		File file(files.get(fileno));
		file.remove(lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno or lineno");
	}
}

void dfs_lte::command::l(const Files& files, const wstring& fileno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		File file(files.get(fileno));
		file.list(1, file.getLines());
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno");
	}
}

void dfs_lte::command::l(const Files& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		unsigned int lineno = lexical_cast<unsigned int>(lineno_s);
		File file(files.get(fileno));
		file.list(lineno, lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno or lineno");
	}
}

void dfs_lte::command::l(const Files& files, const wstring& fileno_s, const wstring& from_lineno_s, const wstring& to_lineno_s)
{
	try
	{
		unsigned int fileno = lexical_cast<unsigned int>(fileno_s);
		unsigned int from_lineno = lexical_cast<unsigned int>(from_lineno_s);
		unsigned int to_lineno = lexical_cast<unsigned int>(to_lineno_s);
		File file(files.get(fileno));
		file.list(from_lineno, to_lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception(L"invalid fileno or lineno");
	}
}
