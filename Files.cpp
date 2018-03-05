// header
#include "Files.h"
#include "File.h"

// using
using namespace dfs_lte;

File& dfs_lte::Files::get(unsigned int fileno) const
{
	if(files.size() < fileno)
		throw dfs_lte::exception(L"invalid fileno");

	return *(files.begin() + --fileno);
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

	files.erase(files.begin() + --fileno);
}
