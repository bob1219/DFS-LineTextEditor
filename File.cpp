// File.cpp
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a source file in DFS-LineTextEditor project.
// This file and DFS-LineTextEditor project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <string>
#include <iostream>
#include <fstream>
#include <cstddef>
#include <algorithm>
#include <iterator>
#include <stdexcept>

// boost
#include <boost/format.hpp>

// header
#include "File.h"
#include "exception.h"

// using
using namespace std;
using namespace boost;

void dfs_lte::File::open(const wstring& filename)
{
	init(filename);

	this->filename = filename;
	isSaved = true;
}

void dfs_lte::File::edit(unsigned int lineno, const wstring& text)
{
	try
	{
		lines.at(--lineno) = text;
		isSaved = false;
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid lineno"};
	}
}

void dfs_lte::File::append(const std::wstring& text)
{
	lines.push_back(text);
	isSaved = false;
}

void dfs_lte::File::insert(unsigned int lineno, const std::wstring& text)
{
	if(lines.size() < lineno)
		throw dfs_lte::exception{L"invalid lineno"};

	lines.insert(begin(lines) + --lineno, text);
	isSaved = false;
}

void dfs_lte::File::write(const wstring& filename) const
{
	// Open a file
	wofstream file;
	file.imbue(locale(""));
	file.open(filename);
	if(file.fail())
		throw dfs_lte::exception{L"failed open file"};

	// Write lines
	for(wstring line: lines)
		file << line << endl;

	isSaved = true;
}

void dfs_lte::File::appends(const vector<wstring>& texts)
{
	for(const auto& text: texts)
		lines.push_back(text);

	isSaved = false;
}

void dfs_lte::File::remove(unsigned int lineno)
{
	if(lines.size() < lineno)
		throw dfs_lte::exception{L"invalid lineno"};

	lines.erase(begin(lines) + --lineno);
	isSaved = false;
}

void dfs_lte::File::list(unsigned int from_lineno, unsigned int to_lineno) const
{
	if(lines.empty())
		throw dfs_lte::exception{L"it is empty"};

	const auto allLinesNumber{lines.size()};
	if(allLinesNumber < from_lineno || allLinesNumber < to_lineno)
		throw dfs_lte::exception{L"invalid lineno"};

	auto i{from_lineno};
	for_each(begin(lines) + --from_lineno, begin(lines) + to_lineno, [&](const auto& line)
	{
		wcout << wformat{L"%1%:\t%2%"} % i % line << endl;
		++i;
	});
}

void dfs_lte::File::init(const wstring& filename)
{
	// Open
	wifstream file;
	file.imbue(locale{""});
	file.open(filename);
	if(file.fail())
		throw dfs_lte::exception{L"failed open file"};

	// Clear
	lines.clear();

	// Read
	wstring line;
	while(getline(file, line))
		lines.push_back(line);
}

void dfs_lte::File::copy(unsigned int lineno, vector<wstring>& cpBuf)
{
	try
	{
		cpBuf.push_back(lines.at(--lineno));
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid lineno"};
	}
}

void dfs_lte::File::copy(unsigned int lineno, unsigned int copy_buf_no, vector<wstring>& cpBuf)
{
	try
	{
		cpBuf.at(--copy_buf_no) = lines.at(--lineno);
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid lineno or copy-buffer-no"};
	}
}

const wstring dfs_lte::File::get(unsigned int lineno) const
{
	try
	{
		return lines.at(--lineno);
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid lineno"};
	}
}
