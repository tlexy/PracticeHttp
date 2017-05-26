#include <iostream>
#include "file_util.h"
#include "file_manager.h"

int main()
{
/*
	std::string str("test_content\n");
	std::string fn("abc.txt");
	FileUtil::writeFile(str, fn);
	
	if (FileUtil::fileExist(fn))
	{
		int size = FileUtil::fileSize(fn);
		std::cout << "create file succeed. file size=" << size << std::endl;
	}
	else
	{
		std::cout << "create file fail." << std::endl;
	}
	std::cout << std::endl;
	std::cout << "now, print the code:" << std::endl;
	std::string content = FileUtil::readFile(std::string("test_file_util.cpp"));
	std::cout << content.c_str() << std::endl;
*/	
	FileManager *mgr = new FileManager();
	FilePtr file = mgr->getFileContent(std::string("abc.txt"));
	if (file)
	{
		std::cout << "file content:" << file->c_str() << std::endl;
	}
	return 0;
}
