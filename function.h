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
		void o(Files& files, const std::wstring& fileno_s);
		void o(Files& files, const std::wstring& fileno_s, const std::wstring& filename);
		void cl(Files& files, const std::wstring& fileno_s);
		void f(const Files& files);
		void e(Files& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void a(Files& files, const std::wstring& fileno_s);
		void i(Files& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void cp(Files& files, const std::wstring& fileno_s, const std::wstring& from_lineno_s, const std::wstring& to_lineno_s);
		void w(const Files& files, const std::wstring& fileno_s);
		void w(const Files& files, const std::wstring& fileno_s, const std::wstring& filename);
		void as(Files& files, const std::wstring& fileno_s);
		void r(Files& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void l(const Files& files, const std::wstring& fileno_s);
	}
}

#endif
