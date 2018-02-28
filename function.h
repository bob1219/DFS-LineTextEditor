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

	namespace command
	{
		void o(Files& files, const std::wstring& fileno);
		void o(Files& files, const std::wstring& fileno, const std::wstring& filename);
		void cl(Files& files, const std::wstring& fileno);
		void f(const Files& files);
		void e(Files& files, const std::wstring& fileno, const std::wstring& lineno);
		void a(Files& files, const std::wstring& fileno);
		void i(Files& files, const std::wstring& fileno, const std::wstring& lineno);
		void cp(Files& files, const std::wstring& fileno, const std::wstring& from_lineno, const std::wstring& to_lineno);
		void w(const Files& files, const std::wstring& fileno);
		void w(const Files& files, const std::wstring& fileno, const std::wstring& filename);
		void as(Files& files, const std::wstring& fileno);
		void r(Files& files, const std::wstring& fileno, const std::wstring& lineno);
	}
}

#endif
