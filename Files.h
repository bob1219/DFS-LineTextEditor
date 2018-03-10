#ifndef FILES_H
#define FILES_H

namespace dfs_lte
{
	class Files
	{
	public:
		Files() = default;
		Files(const Files&) = default;
		Files(const File& file) { add(); }
		File& get(unsigned int fileno) const;
		File& add();
		void close(unsigned int fileno);
		void list() const;
		bool getAllSaved() const;

	private:
		std::list<File> files;
	};
}

#endif
