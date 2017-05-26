/*
* file manager implementation.
* 2017-5-25 by Lin Xing
*/

#ifndef FILE_MANAGER_PRIVATE_H
#define FILE_MANAGER_PRIVATE_H

#include <string>
#include "file_base.h"
#include <unordered_map>

class FileManagerPrivate
{
public:
	FileManagerPrivate();
	FilePtr getFileContent(const std::string& file_name);
	void writeToLocal(FilePtr content, const std::string& to);
private:
	//file path to file content...
	std::unordered_map<std::string, FilePtr> _ptc_map;
//	int _size;
};

#endif
