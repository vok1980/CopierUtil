
#include <iostream>						// for std::cout
#include <string>
#include "boost/filesystem.hpp"			// includes all needed Boost.Filesystem declarations
//#include "boost/iostreams/device/file.hpp"
#include "boost/filesystem/fstream.hpp"

using namespace boost::filesystem;      // for ease of tutorial presentation;
//using namespace boost::iostreams;



int ReadFile(const std::string &strFileName, std::list<std::string> &aList)
{
	path path_list_file(strFileName);

	if ( !exists( path_list_file ) ) 
	{
		std::cerr << "Unknown src path \"" << strFileName << "\"" << std::endl;
		return 1;
	}

	boost::filesystem::ifstream fsList(path_list_file);

	if (!fsList.is_open())
	{
		std::cerr << "Failed to read file \"" + strFileName + "\"" << std::endl;
		return 2;
	}

#define BUF_SIZE	1024

	char szBuf[BUF_SIZE];

	while (fsList.getline(szBuf, BUF_SIZE))
	{
		aList.push_back(szBuf);
	}

	return 0;
}


void ExcludeList(const std::string &strBaseFileList, const std::string &strDiffFileList)
{
	std::list<std::string> aBaseList;
	std::list<std::string> aDiffList;
	
	ReadFile(strBaseFileList, aBaseList);
	ReadFile(strDiffFileList, aDiffList);
	
	std::for_each(aDiffList.begin(), aDiffList.end(), 
		[&aBaseList](const std::string &refLine)
		{
			std::list<std::string>::iterator it = std::find(aBaseList.begin(), aBaseList.end(), refLine);

			if ( it != aBaseList.end() )
			{
				aBaseList.erase(it);
			}
		}
	);

	std::for_each(aBaseList.begin(), aBaseList.end(), 
		[](const std::string &refLine)
		{
			std::cout << refLine << std::endl;
		}
	);

	int a = 567;
}