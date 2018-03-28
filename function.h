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

namespace dfs_lte
{
	// declaration
	class File;

	[[noreturn]] void CommandLine(vector<File>& files);
	void CommandProcess(vector<File>& files, const std::wstring& command);
	inline void welcome() { std::wcout << L"welcome to DFS-LineTextEditor!" << std::endl; }

	namespace command
	{
		void o(vector<File>& files, const std::wstring& fileno_s);
		void o(vector<File>& files, const std::wstring& fileno_s, const std::wstring& filename);
		void cl(vector<File>& files, const std::wstring& fileno_s);
		void f(const vector<File>& files);
		void e(vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void a(vector<File>& files, const std::wstring& fileno_s);
		void i(vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void cp(vector<File>& files, const std::wstring& fileno_s, const std::wstring& from_lineno_s, const std::wstring& to_lineno_s);
		void w(const vector<File>& files, const std::wstring& fileno_s);
		void w(const vector<File>& files, const std::wstring& fileno_s, const std::wstring& filename);
		void as(vector<File>& files, const std::wstring& fileno_s);
		void r(vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void l(const vector<File>& files, const std::wstring& fileno_s);
		void l(const vector<File>& files, const std::wstring& fileno_s, const std::wstring& lineno_s);
		void l(const vector<File>& files, const std::wstring& fileno_s, const std::wstring& from_lineno_s, const std::wstring& to_lineno_s);
	}
}

#endif
