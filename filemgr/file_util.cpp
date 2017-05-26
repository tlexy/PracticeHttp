#include "file_util.h"
#include "../base/common.hpp"
#include <fstream>
#include <boost/filesystem.hpp>
//#include "file_base.h"

namespace FileUtil
{

	void  readFileTo(const std::string& file_name, FilePtr to)
	{
		std::string line;
		std::ifstream ifile(file_name.c_str());
		while(std::getline(ifile, line))
		{
			to->append(line);
		}
		ifile.close();
	}

	FilePtr readFile(const std::string& file_name)
	{
		FilePtr ptr = Creator<std::string>::Create();
		readFileTo(file_name, ptr);
		return ptr;
	}

	int fileSize(const std::string& file_name)
	{
		std::ifstream is(file_name.c_str(), std::ifstream::binary);
		int len = -1;
		if (is)
		{
			is.seekg(0, is.end);
			len = is.tellg();
			is.seekg(0, is.beg);
		}
		is.close();
		return len;
	}

	bool fileExist(const std::string& file_name)
	{
		boost::filesystem::path p(file_name.c_str());
		return boost::filesystem::exists(p);
	}

	int writeFile(FilePtr from, const std::string& file_name, bool force)
	{
		if (!force && fileExist(file_name))
		{
			return 1;
		}
		std::ofstream ofile(file_name.c_str(), std::ofstream::binary | std::ofstream::out);
		ofile.write(from->c_str(), from->size());
		ofile.close();
		return 0;
	}

}
