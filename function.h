#ifndef FUNCTION_H
#define FUNCTION_H

// standard library
#include <string>

namespace dfs_lte
{
	// declaration
	class Files;

	[[noreturn]] void CommandLine(const Files& files);
	void CommandProcess(const Files& files, const std::wstring& command);
}

#endif
