// commands.cpp
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a source file in DFS-LineTextEditor project.
// This file and DFS-LineTextEditor project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <string>
#include <iterator>

// boost
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

// header
#include "function.h"
#include "File.h"
#include "exception.h"

// using
using namespace dfs_lte;
using namespace std;
using namespace boost;

void dfs_lte::command::o(vector<File>& files, const wstring& fileno_s)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s); // Convert string of fileno to unsigned integer

		if(fileno > files.size())
			throw dfs_lte::exception{L"invalid fileno};

		const auto file = begin(files) + --fileno;
		file->open(file->getFilename());
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::o(vector<File>& files, const wstring& fileno_s, const wstring& filename)
{
	if(fileno_s == L"-n")
		files.push_back(File{filename});
	else
	{
		try
		{
			const auto fileno = lexical_cast<unsigned int>(fileno_s); // Convert string of fileno to unsigned integer
			files.at(--fileno).open(filename);
		}
		catch(bad_lexical_cast)
		{
			throw dfs_lte::exception{L"invalid fileno"};
		}
	}
}

void dfs_lte::command::cl(vector<File>& files, const wstring& fileno_s)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s); // Convert string of fileno to unsigned integer
		
		if(fileno > files.size())
			throw dfs_lte::exception{L"invalid fileno"};

		files.erase(begin(files) + --fileno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::f(const vector<File>& files)
{
	files.list();
}

void dfs_lte::command::e(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		// Convert string of fileno and lineno to unsigned integer
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);

		files.at(--fileno).edit(lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
}

void dfs_lte::command::a(vector<File>& files, const wstring& fileno_s)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s); // Convert string of fileno to unsigned integer
		files.at(--fileno).append();
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::i(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		// Convert string of fileno and lineno to unsigned integer
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);

		files.at(--fileno).insert(lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
}

void dfs_lte::command::cp(vector<File>& files, const wstring& fileno_s, const wstring& from_lineno_s, const wstring& to_lineno_s)
{
	try
	{
		// Convert string of fileno and from-lineno and to-lineno to unsigned integer
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto from_lineno = lexical_cast<unsigned int>(from_lineno_s);
		const auto to_lineno = lexical_cast<unsigned int>(to_lineno_s);

		files.at(--fileno).copy(from_lineno, to_lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
}

void dfs_lte::command::w(const vector<File>& files, const wstring& fileno_s)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s); // Convert string of fileno to unsigned integer
		files.at(--fileno).write();
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::w(const vector<File>& files, const wstring& fileno_s, const wstring& filename)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s); // Convert string of fileno to unsigned integer
		files.at(--fileno).write(filename);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::as(vector<File>& files, const wstring& fileno_s)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s); // Convert string of fileno to unsigned integer
		files.at(--fileno).appends();
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::r(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		// Convert string of fileno and lineno to unsigned integer
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);

		files.at(--fileno).remove(lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
}

void dfs_lte::command::l(const vector<File>& files, const wstring& fileno_s)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s); // Convert string of fileno to unsigned integer

		if(fileno > files.size())
			throw dfs_lte::exception{L"invalid fileno"};

		const auto file = begin(files) + --fileno;
		file->list(1, file->getLines());
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::l(const vector<File>& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		// Convert strig of fileno and lineno to unsigned integer
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);
		files.at(--fileno).list(lineno, lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
}

void dfs_lte::command::l(const vector<File>& files, const wstring& fileno_s, const wstring& from_lineno_s, const wstring& to_lineno_s)
{
	try
	{
		// Convert string of fileno and from-lineno and to-lineno to unsigned integer
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto from_lineno = lexical_cast<unsigned int>(from_lineno_s);
		const auto to_lineno = lexical_cast<unsigned int>(to_lineno_s);

		files.at(--fileno).list(from_lineno, to_lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
}
