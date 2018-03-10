// standard library
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <cstddef>
#include <algorithm>

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
		throw dfs_lte::exception(L"file is not saved");

	wifstream file;
	file.imbue(locale(""));
	file.open(filename);
	if(file.fail())
		throw dfs_lte::exception(L"failed open file");

	lines.clear();

	wstring line;
	while(getline(file, line))
		lines.push_back(line);

	this->filename = filename;
}

void dfs_lte::File::edit(unsigned int lineno)
{
	if(lines.size() < lineno)
		throw dfs_lte::exception(L"invalid lineno");

	list<wstring>::iterator i = lines.begin() + --lineno;
	wstring bLine = *i;

	wcout << L"B: " << bLine << endl;
	wcout << L"A: ";

	wstring aLine;
	getline(wcin, aLine);

	*i = aLine;
	isSaved = false;
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
		throw dfs_lte::exception(L"invalid lineno");

	wstring text;
	wcout << L"text: ";
	getline(wcin, text);

	lines.insert(lines.begin() + --lineno, text);
	isSaved = false;
}

void dfs_lte::File::copy(unsigned int from_lineno, unsigned int to_lineno)
{
	const size_t size = lines.size();
	if(size < from_lineno || size < to_lineno)
		throw dfs_lte::exception(L"invalid lineno");

	list<wstring>::iterator i = lines.begin();
	*(i + --to_lineno) = *(i + --from_lineno);
	isSaved = false;
}

void dfs_lte::File::write(const wstring& filename) const
{
	wofstream file;
	file.imbue(locale(""));
	file.open(filename);
	if(file.fail())
		throw dfs_lte::exception(L"failed open file");

	for(wstring line: lines)
		file << line << endl;

	isSaved = true;
}

void dfs_lte::File::appends()
{
	wcout << L"end: ;" << endl;
	while(true)
	{
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
		throw dfs_lte::exception(L"invalid lineno");

	lines.erase(lines.begin() + --lineno);
	isSaved = false;
}

void dfs_lte::File::list(unsigned int from_lineno, unsigned int to_lineno) const
{
	list<wstring>::iterator from_line = *(lines.begin() + --from_lineno);
	list<wstring>::iterator to_line = *(lines.begin() + to_lineno);

	unsigned int no = 1;
	for_each(from_line, to_line, [](const wstring& line)
	{
		wcout << wformat(L"%1%:\t%2%") % no % line << endl;
		++no;
	});
