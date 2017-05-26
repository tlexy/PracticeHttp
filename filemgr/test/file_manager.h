/*
* file manager that cache file, send file to client,etc.
* 2017-5-24 by Lin Xing
*/

#include <string>
#include "file_base.h"

class FileManagerPrivate;

namespace FileSize
{
	enum file_size
	{
		KB = 1024,
		MB = 1024*1024,
		GB = 1024*1024*1024,
	};
}

//should be run in the singleton model?
class FileManager
{
public:
	FileManager();
	FilePtr getFileContent(const std::string& file_name);
	void writeToLocal(FilePtr content, const std::string& to);
private:
	boost::shared_ptr<FileManagerPrivate> _d;
};
