// standard library
#include <iostream>
#include <iterator>
#include <functional>

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
	const auto no = --fileno;
	if(files.size() < no)
		throw dfs_lte::exception{L"invalid fileno"};
	return files.at(no);
}

File& dfs_lte::Files::add()
{
	files.push_back(File{});
	return *(end(files) - 1);
}

void dfs_lte::Files::close(unsigned int fileno)
{
	if(files.size() < fileno)
		throw dfs_lte::exception(L"invalid fileno");

	files.erase(begin(files) + --fileno);
}

void dfs_lte::Files::list() const
{
	unsigned int i{1};
	for(const auto& file: files)
	{
		wcout << wformat(L"%1%:\t%2%") % i % file.getFilename() << endl;
		++i;
	}
}

bool dfs_lte::Files::getAllSaved() const
{
	return all_of(begin(files), end(files), mem_fn(&File::getIsSaved));
}
