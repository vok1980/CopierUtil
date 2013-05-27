
#include <iostream>						// for std::cout
#include <string>
#include "boost/filesystem.hpp"			// includes all needed Boost.Filesystem declarations
//#include "boost/iostreams/device/file.hpp"
#include "boost/filesystem/fstream.hpp"

using namespace boost::filesystem;      // for ease of tutorial presentation;
//using namespace boost::iostreams;




void CopyList(const std::string &strFileList, const std::string &strSrcPath, const std::string &strDstPath)
{
	path path_src_dir(strSrcPath);
	path path_dest_dir(strDstPath);
	path path_list_file(strFileList);

	if ( !exists( path_src_dir ) ) 
	{
		std::cerr << "Unknown src path \"" << strSrcPath << "\"" << std::endl;
		return ;
	}

	if ( !exists( path_dest_dir ) ) 
	{
		boost::system::error_code errcode;
		
		if (!create_directories(path_dest_dir))
		{
			std::cerr << "Failed to create directory \"" + strDstPath + "\"" << std::endl;
			return ;
		}
	}

//	wfile fsList(strFileList);
//	fsList.open(strFileList, BOOST_IOS::in, BOOST_IOS::in);

	boost::filesystem::wifstream fsList(path_list_file);
	
	if (!fsList.is_open())
	{
		std::cerr << "Failed to read file \"" + strFileList + "\"" << std::endl;
	}

#define BUF_SIZE	1024
	wchar_t szBuf[BUF_SIZE];
	std::list<std::wstring> aList;

	while (fsList.getline(szBuf, BUF_SIZE))
	{
		aList.push_back(szBuf);
	}


	for (std::list<std::wstring>::iterator it = aList.begin(); it != aList.end(); ++it)
	{
		path src_file( path_src_dir );
		path dst_file( path_dest_dir );

		src_file += *it;
		dst_file += *it;
		
		//boost::system::error_code errcode;
		copy(src_file, dst_file/*, &errcode*/);
	}
}