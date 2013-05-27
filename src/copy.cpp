
#include <iostream>						// for std::cout
#include <string>
#include "boost/filesystem.hpp"			// includes all needed Boost.Filesystem declarations

using namespace boost::filesystem;      // for ease of tutorial presentation;




void CopyList(const std::string &strFileList, const std::string &strSrcPath, const std::string &strDstPath)
{
	path path_src_dir(strSrcPath);
	path path_dest_dir(strDstPath);

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






}