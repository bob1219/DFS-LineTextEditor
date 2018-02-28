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
		void o(const Files& files, const std::wstring& fileno);
		void o(const Files& files, const std::wstring& fileno, const std::wstring& filename);
		void cl(const Files& files, const std::wstring& fileno);
		void f(const Files& files);
		void e(const Files& files, const std::wstring& fileno, const std::wstring& lineno);
		void a(const Files& files, const std::wstring& fileno);
		void i(const Files& files, const std::wstring& fileno, const std::wstring& lineno);
		void cp(const Files& files, const std::wstring& fileno, const std::wstring& from_lineno, const std::wstring& to_lineno);
		void w(const Files& files, const std::wstring& fileno);
		void w(const Files& files, const std::wstring& fileno, const std::wstring& filename);
		void as(const Files& files, const std::wstring& fileno);
		void r(const Files& files, const std::wstring& fileno, const std::wstring& lineno);
	}
}

#endif
