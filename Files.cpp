// header
#include "class.h"

// using
using namespace dfs_lte;

File dfs_lte::Files::get(unsigned int fileno) const
{
	return *(files.begin() + --fileno);
}
