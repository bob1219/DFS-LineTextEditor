// function.h
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a header file in DFS-LineTextEditor project.
// This file and DFS-LineTextEditor project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

#ifndef FUNCTION_H
#define FUNCTION_H

// standard library
#include <string>
#include <iostream>
#include <vector>

namespace dfs_lte
{
	// declaration
	class File;

	[[noreturn]] void CommandLine(const File& file);
	void CommandProcess(std::vector<File>& files, std::vector<std::wstring>& cpBuf, const std::wstring& command);
	inline void welcome() { std::wcout << L"welcome to DFS-LineTextEditor!" << std::endl; }

	namespace command
	{
		void o(std::vector<File>& files, const std::wstring& fileno_s);
		void o(std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& filename);
		void cl(std::vector<File>& files, const std::wstring& fileno_s);
		void f(const std::vector<File>& files);
		void e(std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void e(std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s, const std::wstring& copy_buf_no_s, const std::vector<std::wstring>& cpBuf);
		void a(std::vector<File>& files, const std::wstring& fileno_s);
		void a(std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& copy_buf_no_s, const std::vector<std::wstring>& cpBuf);
		void i(std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void i(std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s, const std::wstring& copy_buf_no_s, const std::vector<std::wstring>& cpBuf);
		void cp(std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s, const std::wstring& copy_buf_no_s, std::vector<std::wstring>& cpBuf);
		void w(const std::vector<File>& files, const std::wstring& fileno_s);
		void w(const std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& filename);
		void as(std::vector<File>& files, const std::wstring& fileno_s);
		void r(std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void l(const std::vector<File>& files, const std::wstring& fileno_s);
		void l(const std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void l(const std::vector<File>& files, const std::wstring& fileno_s, const std::wstring& from_lineno_s, const std::wstring& to_lineno_s);
		void fcl(std::vector<File>& files, const std::wstring& fileno_s);
	}
}

#endif
