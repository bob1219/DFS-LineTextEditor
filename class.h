#ifndef CLASS_H
#define CLASS_H

// standard library
#include <string>
#include <list>

namespace dfs_lte
{
	class File
	{
	public:
		File() = default;
		File(const File&) = delete;
		File(const std::wstring& filename) { open(filename); }
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

	private:
		std::list<std::wstring> lines;
		std::wstring filename;
	};
}

#endif
