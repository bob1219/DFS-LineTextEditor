// standard library
#include <string>
#include <iostream>
#include <fstream>

// header
#include "class.h"

// using
using namespace std;

void dfs_lte::File::read(const wstring& filename)
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
