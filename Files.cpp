// standard library
#include <iostream>

// boost
#include <boost/format.hpp>

// header
#include "Files.h"
#include "File.h"
#include "exception.h"

// using
using namespace dfs_lte;
using namespace std;
using namespace boost;

const File& dfs_lte::Files::get(unsigned int fileno) const
{
	if(files.size() < fileno)
		throw dfs_lte::exception(L"invalid fileno");

	auto i = files.begin();
	for(unsigned int count = 0; count < fileno; ++count)
		++i;

	return *i;
}

File& dfs_lte::Files::add()
{
	File file;
	files.push_back(file);
	return file;
}

void dfs_lte::Files::close(unsigned int fileno)
{
	if(files.size() < fileno)
		throw dfs_lte::exception(L"invalid fileno");

	auto i = files.begin();
	for(unsigned int count = 0; count < fileno; ++count)
		++i;

	files.erase(i);
}

void dfs_lte::Files::list() const
{
	int i = 1;
	for(const File& file: files)
	{
		wcout << wformat(L"%1%:\t%2%") % i % file.getFilename() << endl;
		++i;
	}
}

bool dfs_lte::Files::getAllSaved() const
{
	bool result = true;
	for(const File& file: files)
		result = result && file.getIsSaved();

	return result;
}
