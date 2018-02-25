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
		File(const std::wstring& filename) { read(filename); }
		void read(const std::wstring& filename);

	private:
		std::list<std::wstring> lines;
		std::wstring filename;
	};
}

#endif
