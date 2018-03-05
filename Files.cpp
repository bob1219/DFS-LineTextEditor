// header
#include "class.h"

// using
using namespace dfs_lte;

File dfs_lte::Files::get(unsigned int fileno) const
{
	return *(files.begin() + --fileno);
}

void dfs_lte::Files::add()
{
	files.push_back(File());
}

void dfs_lte::Files::close(unsigned int fileno)
{
	files.erase(files.begin() + --fileno);
}
