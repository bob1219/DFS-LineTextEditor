#ifndef FILES_H
#define FILES_H

// standard library
#include <vector>

// header
#include "File.h"

namespace dfs_lte
{
	class Files
	{
	public:
		Files() = default;
		Files(const Files&) = default;
		Files(Files&&) = default;
		Files(const File& file) { files.push_back(file); }

		Files& operator=(const Files&) = default;
		Files& operator=(Files&&) = default;

		const File& get(unsigned int fileno) const;
		File& get(unsigned int fileno) { return const_cast<File&>(static_cast<const Files&>(*this).get(fileno)); }
		File& add();
		void close(unsigned int fileno);
		void list() const;
		bool getAllSaved() const;

	private:
		std::vector<File> files;
	};
}

#endif
