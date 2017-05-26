#ifndef FILE_UTILITY_H
#define FILE_UTILITY_H

#include "file_base.h"
#include <string>

namespace FileUtil
{

	void readFileTo(const std::string& file_name, FilePtr to);	
	FilePtr readFile(const std::string& file_name);
	int fileSize(const std::string& file_name);
	bool fileExist(const std::string& file_name);
	int writeFile(FilePtr from, const std::string& to_name, bool force = true);
}

#endif
