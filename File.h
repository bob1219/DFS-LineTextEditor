#ifndef FILE_H
#define FILE_H

// standard library
#include <string>
#include <vector>
#include <cstddef>

namespace dfs_lte
{
	class File
	{
	public:
		File() : isSaved{true} {}
		File(const File&) = default;
		File(File&&) = default;
		File(const std::wstring& filename) : isSaved{true} { open(filename); }

		File& operator=(const File&) = default;
		File& operator=(File&&) = default;

		void open(const std::wstring& filename);
		std::wstring getFilename() const { return filename; }
		void edit(unsigned int lineno);
		void append();
		void insert(unsigned int lineno);
		void copy(unsigned int from_lineno, unsigned int to_lineno);
		void write() const { write(filename); }
		void write(const std::wstring& filename) const;
		void appends();
		void remove(unsigned int lineno);
		bool getIsSaved() const { return isSaved; }
		void list(unsigned int from_lineno, unsigned int to_lineno) const;
		std::size_t getLines() const { return lines.size(); }

	private:
		std::vector<std::wstring> lines;
		std::wstring filename;
		mutable bool isSaved;
	};
}

#endif
