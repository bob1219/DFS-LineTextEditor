// commands.cpp
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a source file in DFS-LineTextEditor project.
// This file and DFS-LineTextEditor project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <string>
#include <iterator>
#include <iostream>

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
		const auto fileno = lexical_cast<unsigned int>(fileno_s);

		if(fileno > files.size())
			throw dfs_lte::exception{L"invalid fileno"};

		// Open
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
			const auto fileno = lexical_cast<unsigned int>(fileno_s);
			files.at(--fileno).open(filename); // Open
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
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		
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
	auto i = 1;
	for(const auto& file: files)
	{
		wcout << wformat{L"%1%:\t%2%"} % i % file.getFilename() << endl;
		++i;
	}
}

void dfs_lte::command::e(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);

		// Edit
		files.at(--fileno).edit(lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
}

void dfs_lte::command::e(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s, const wstring& copy_buf_no_s, const vector<wstring>& cpBuf)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);
		const auto copy_buf_no = lexical_cast<unsigned int>(copy_buf_no_s);

		// Edit
		files.at(--fileno).edit(lineno, cpBuf.at(--copy_buf_no));
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno or copy-buffer-no"};
	}
}

void dfs_lte::command::a(vector<File>& files, const wstring& fileno_s)
{
	try
	{
		wstring text;
		wcout << L"text: ";
		getline(wcin, text);

		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		files.at(--fileno).append(text); // Append
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::a(vector<File>& files, const wstring& fileno_s, const wstring& copy_buf_no_s, const vector<wstring>& cpBuf)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto copy_buf_no = lexical_cast<unsigned int>(copy_buf_no_s);

		// Append
		files.at(--fileno).append(cpBuf.at(--copy_buf_no));
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or copy-buffer-no"};
	}
}

void dfs_lte::command::i(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);

		wstring text;
		wcout << L"text: ";
		getline(wcin, text);

		// Insert
		files.at(--fileno).insert(lineno, text);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
}

void dfs_lte::command::i(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s, const wstring& copy_buf_no_s, const vector<wstring>& cpBuf)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);
		const auto copy_buf_no = lexical_cast<unsigned int>(copy_buf_no_s);

		// Insert
		files.at(--fileno).insert(lineno, cpBuf.at(--copy_buf_no));
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::excepiton{L"invalid fileno or lineno or copy-buffer-no"};
	}
}

void dfs_lte::command::cp(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s, const wstring& copy_buf_no_s, vector<wstring>& cpBuf)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}

	if(copy_buf_no_s == L"-n")
		files.at(--fileno).copy(lineno, cpBuf); // Copy
	else
	{
		try
		{
			const auto copy_buf_no = lexical_cast<unsigned int>(copy_buf_no_s);
			files.at(--fileno).copy(lineno, copy_buf_no, cpBuf); // Copy
		}
		catch(bad_lexical_cast)
		{
			throw dfs_lte::exception{L"invalid copy-buffer-no"};
		}
	}
}

void dfs_lte::command::w(const vector<File>& files, const wstring& fileno_s)
{
	try
	{
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		files.at(--fileno).write(); // Write
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
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		files.at(--fileno).write(filename); // Write
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
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		vector<wstring> texts;

		wcout << L"end: ;" << endl;
		while(true)
		{
			wstring text;
			wcout << L'>';
			getline(wcin, text);
			texts.push_back(text);
		}

		// Append
		files.at(--fileno).appends(texts);
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
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);

		// Remove
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

		// Print list
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
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto lineno = lexical_cast<unsigned int>(lineno_s);

		// Print list
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
		const auto fileno = lexical_cast<unsigned int>(fileno_s);
		const auto from_lineno = lexical_cast<unsigned int>(from_lineno_s);
		const auto to_lineno = lexical_cast<unsigned int>(to_lineno_s);

		// Print list
		files.at(--fileno).list(from_lineno, to_lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
}
