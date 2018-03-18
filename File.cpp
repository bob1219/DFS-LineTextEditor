// standard library
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <cstddef>
#include <algorithm>
#include <iterator>

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
	if(!isSaved)
		throw dfs_lte::exception{L"file is not saved"};

	// Open a file
	wifstream file;
	file.imbue(locale{""});
	file.open(filename);
	if(file.fail())
		throw dfs_lte::exception{L"failed open file"};

	lines.clear();

	// Read
	wstring line;
	while(getline(file, line))
		lines.push_back(line);

	this->filename = filename; // Setting filename
	isSaved = true; // Setting save situation
}

void dfs_lte::File::edit(unsigned int lineno)
{
	try
	{
		wstring& line{lines.at(--lineno)};
		wcout << L"B: " << line << endl;
		wcout << L"A: ";

		wstring aLine;
		getline(wcin, aLine);

		line = aLine;
		isSaved = false;
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid lineno"};
	}
}

void dfs_lte::File::append()
{
	wstring text;
	wcout << L"text: ";
	getline(wcin, text);

	lines.push_back(text);
	isSaved = false;
}

void dfs_lte::File::insert(unsigned int lineno)
{
	if(lines.size() < lineno)
		throw dfs_lte::exception{L"invalid lineno"};

	wstring text;
	wcout << L"text: ";
	getline(wcin, text);

	lines.insert(lines.begin() + --lineno, text);
	isSaved = false;
}

void dfs_lte::File::copy(unsigned int from_lineno, unsigned int to_lineno)
{
	try
	{
		lines.at(--to_lineno) = lines.at(--from_lineno);
	}
	catch(out_of_range)
	{
		throw dfs_lte::exception{L"invalid lineno"};
	}

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

void dfs_lte::File::appends()
{
	wcout << L"end: ;" << endl;
	while(true)
	{
		// Input text
		wstring text;
		wcout << L'>';
		getline(wcin, text);
		if(text == L";")
			break;

		lines.push_back(text);
	}

	isSaved = false;
}

void dfs_lte::File::remove(unsigned int lineno)
{
	if(lines.size() < lineno)
		throw dfs_lte::exception{L"invalid lineno"};

	lines.erase(lines.begin() + --lineno);
	isSaved = false;
}

void dfs_lte::File::list(unsigned int from_lineno, unsigned int to_lineno) const
{
	if(lines.empty())
		throw dfs_lte::exception{L"it is empty"};

	const auto allLinesNumber = lines.size();
	if(allLinesNumber < from_lineno || allLinesNumber < to_lineno)
		throw dfs_lte::exception{L"invalid lineno"};

	unsigned int no{1};
	for_each(lines.begin() + --from_lineno, lines.begin() + to_lineno, [&](const auto& line)
	{
		wcout << wformat(L"%1%:\t%2%") % no % line << endl;
		++no;
	});
}
