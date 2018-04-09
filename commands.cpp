// commands.cpp
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a source file in DFS-LineTextEditor project.
// This file and DFS-LineTextEditor project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <string>
#include <iterator>
#include <iostream>
#include <stdexcept>

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
		auto fileno{lexical_cast<unsigned int>(fileno_s)};

		if(fileno > files.size())
			throw dfs_lte::exception{L"invalid fileno"};

		// Open
		const auto file{std::begin(files) + --fileno};
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
			auto fileno{lexical_cast<unsigned int>(fileno_s)};
			files.at(--fileno).open(filename); // Open
		}
		catch(bad_lexical_cast)
		{
			throw dfs_lte::exception{L"invalid fileno"};
		}
		catch(out_of_range)
		{
			throw dfs_lte::exception{L"invalid fileno"};
		}
	}
}

void dfs_lte::command::cl(vector<File>& files, const wstring& fileno_s)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		
		if(fileno > files.size())
			throw dfs_lte::exception{L"invalid fileno"};

		if(!files.at(--fileno).getIsSaved())
			throw dfs_lte::exception{L"Please save a file"};

		files.erase(std::begin(files) + fileno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::f(const vector<File>& files)
{
	auto i{1};
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
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		auto lineno{lexical_cast<unsigned int>(lineno_s)};

		// Get
		auto& file{files.at(--fileno)};
		auto s{file.get(lineno)};

		// Edit
		wcout << L"B: " << s << endl;
		wcout << L"A: ";

		wstring text;
		getline(wcin, text);

		file.edit(lineno, text);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::e(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s, const wstring& copy_buf_no_s, const vector<wstring>& cpBuf)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		auto lineno{lexical_cast<unsigned int>(lineno_s)};
		auto copy_buf_no{lexical_cast<unsigned int>(copy_buf_no_s)};

		// Edit
		files.at(--fileno).edit(lineno, cpBuf.at(--copy_buf_no));
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno or copy-buffer-no"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid copy-buffer-no"};
	}
}

void dfs_lte::command::a(vector<File>& files, const wstring& fileno_s)
{
	try
	{
		wstring text;
		wcout << L"text: ";
		getline(wcin, text);

		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		files.at(--fileno).append(text); // Append
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::a(vector<File>& files, const wstring& fileno_s, const wstring& copy_buf_no_s, const vector<wstring>& cpBuf)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		auto copy_buf_no{lexical_cast<unsigned int>(copy_buf_no_s)};

		// Append
		files.at(--fileno).append(cpBuf.at(--copy_buf_no));
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or copy-buffer-no"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno or copy-buffer-no"};
	}
}

void dfs_lte::command::i(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		auto lineno{lexical_cast<unsigned int>(lineno_s)};

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
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::i(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s, const wstring& copy_buf_no_s, const vector<wstring>& cpBuf)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		auto lineno{lexical_cast<unsigned int>(lineno_s)};
		auto copy_buf_no{lexical_cast<unsigned int>(copy_buf_no_s)};

		// Insert
		files.at(--fileno).insert(lineno, cpBuf.at(--copy_buf_no));
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno or copy-buffer-no"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno or copy-buffer-no"};
	}
}

void dfs_lte::command::cp(vector<File>& files, const wstring& fileno_s, const wstring& lineno_s, const wstring& copy_buf_no_s, vector<wstring>& cpBuf)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		auto lineno{lexical_cast<unsigned int>(lineno_s)};

		if(copy_buf_no_s == L"-n")
			files.at(--fileno).copy(lineno, cpBuf); // Copy
		else
		{
			const auto copy_buf_no{lexical_cast<unsigned int>(copy_buf_no_s)};
			files.at(--fileno).copy(lineno, copy_buf_no, cpBuf); // Copy
		}
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno or copy-buffer-no"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::w(const vector<File>& files, const wstring& fileno_s)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		files.at(--fileno).write(); // Write
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::w(const vector<File>& files, const wstring& fileno_s, const wstring& filename)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		files.at(--fileno).write(filename); // Write
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::as(vector<File>& files, const wstring& fileno_s)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		vector<wstring> texts;

		wcout << L"end: ;" << endl;
		while(true)
		{
			wstring text;
			wcout << L'>';
			getline(wcin, text);

			if(text == L";")
				break;

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
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		auto lineno{lexical_cast<unsigned int>(lineno_s)};

		// Remove
		files.at(--fileno).remove(lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::l(const vector<File>& files, const wstring& fileno_s)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};

		if(fileno > files.size())
			throw dfs_lte::exception{L"invalid fileno"};

		// Print list
		const auto file{std::begin(files) + --fileno};
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
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		auto lineno{lexical_cast<unsigned int>(lineno_s)};

		// Print list
		files.at(--fileno).list(lineno, lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::l(const vector<File>& files, const wstring& fileno_s, const wstring& from_lineno_s, const wstring& to_lineno_s)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};
		auto from_lineno{lexical_cast<unsigned int>(from_lineno_s)};
		auto to_lineno{lexical_cast<unsigned int>(to_lineno_s)};

		// Print list
		files.at(--fileno).list(from_lineno, to_lineno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno or lineno"};
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}

void dfs_lte::command::fcl(vector<File>& files, const wstring& fileno_s)
{
	try
	{
		auto fileno{lexical_cast<unsigned int>(fileno_s)};

		if(fileno > files.size())
			throw dfs_lte::exception{L"invalid fileno"};

		files.erase(std::begin(files) + --fileno);
	}
	catch(bad_lexical_cast)
	{
		throw dfs_lte::exception{L"invalid fileno"};
	}
}
