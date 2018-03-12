// standard library
#include <iostream>
#include <iterator>

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
	advance(i, --fileno);

	return *i;
}

File& dfs_lte::Files::add()
{
	files.push_back(File());
	auto end = files.end();
	return *--end;
}

void dfs_lte::Files::close(unsigned int fileno)
{
	if(files.size() < fileno)
		throw dfs_lte::exception(L"invalid fileno");

	auto i = files.begin();
	advance(i, --fileno);

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
