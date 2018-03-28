// exception.h
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a header file in DFS-LineTextEditor project.
// This file and DFS-LineTextEditor project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

#ifndef EXCEPTION_H
#define EXCEPTION_H

// standard library
#include <string>

namespace dfs_lte
{
	class exception
	{
	public:
		// Constructors
		explicit exception(const std::wstring& _message) : message{_message} {}
		exception(const exception&) = default;
		exception(exception&&) = default;

		// Operators
		exception& operator=(const exception&) = default;
		exception& operator=(exception&&) = default;

		auto getMessage() const { return message; }

	private:
		std::wstring message;
	};
}

#endif
