#include "../../base/common.hpp"
#include "file_manager.h"
#include "file_manager_private.h"

FileManager::FileManager()
	:_d(Creator<FileManagerPrivate>::Create())
{
}

FilePtr FileManager::getFileContent(const std::string& file_name)
{
	return _d->getFileContent(file_name);
}

void FileManager::writeToLocal(FilePtr content, const std::string& to)
{
	_d->writeToLocal(content, to);
}
