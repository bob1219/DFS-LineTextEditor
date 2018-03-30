// File.h
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a header file in DFS-LineTextEditor project.
// This file and DFS-LineTextEditor project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

#ifndef FILE_H
#define FILE_H

// standard library
#include <string>
#include <vector>
#include <cstddef>
#include <stdexcept>

// header
#include "exception.h"

namespace dfs_lte
{
	class File
	{
	public:
		// Constructors
		File() : isSaved{true} {}
		File(const File&) = default;
		File(File&&) = default;
		explicit File(const std::wstring& _filename) : filename{_filename}, isSaved{true} { init(_filename); }

		// Operators
		File& operator=(const File&) = default;
		File& operator=(File&&) = default;

		void open(const std::wstring& filename);
		auto getFilename() const { return filename; }
		void edit(unsigned int lineno, const std::wstring& text);
		void append(const std::wstring& text);
		void insert(unsigned int lineno, const std::wstring& text);
		void write() const { write(filename); }
		void write(const std::wstring& filename) const;
		void appends(const std::vector<std::wstring>& texts);
		void remove(unsigned int lineno);
		auto getIsSaved() const { return isSaved; }
		void list(unsigned int from_lineno, unsigned int to_lineno) const;
		auto getLines() const { return lines.size(); }
		void copy(unsigned int lineno, std::vector<std::wstring>& cpBuf);
		void copy(unsigned int lineno, unsigned int copy_buf_no, std::vector<std::wstring>& cpBuf);

		const std::wstring get(unsigned int lineno) const
		{
			try
			{
				return lines.at(--lineno);
			}
			catch(std::out_of_range)
			{
				throw dfs_lte::exception{L"invalid lineno"};
			}
		}

	private:
		std::vector<std::wstring> lines;
		std::wstring filename;
		mutable bool isSaved;
		void init(const std::wstring& filename);
	};
}

#endif
