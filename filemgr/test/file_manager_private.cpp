#include "file_manager_private.h"
#include "file_util.h"
#include "../../base/common.hpp"

FileManagerPrivate::FileManagerPrivate()
{}

FilePtr FileManagerPrivate::getFileContent(const std::string& file_name)
{
	if (_ptc_map.find(file_name) != _ptc_map.end())
	{
		return _ptc_map[file_name];
	}

	if (!FileUtil::fileExist(file_name))
	{
		return FilePtr();
	}
	
	FilePtr ptr = Creator<std::string>::Create();
	FileUtil::readFileTo(file_name, ptr);
	_ptc_map[file_name] = ptr;

	return ptr;
}

void FileManagerPrivate::writeToLocal(FilePtr content, const std::string& to)
{
	FileUtil::writeFile(content, to);
}
