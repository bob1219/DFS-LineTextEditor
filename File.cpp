// standard library
#include <string>
#include <iostream>
#include <fstream>
#include <list>

// header
#include "class.h"

// using
using namespace std;

void dfs_lte::File::open(const wstring& filename)
{
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
	list<wstring>::iterator i = lines.begin() + --lineno;
	wstring bLine = *i;

	wcout << L"B: " << bLine << endl;
	wcout << L"A: ";

	wstring aLine;
	getline(wcin, aLine);

	*i = aLine;
}
