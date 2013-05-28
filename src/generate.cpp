
#include <iostream>						// for std::cout
#include <algorithm>

#include "boost/filesystem.hpp"			// includes all needed Boost.Filesystem declarations

using namespace boost::filesystem;      // for ease of tutorial presentation;
										



int GenerateList( const boost::filesystem::path &dir_path, const boost::filesystem::path &base_dir_path )
{
	directory_iterator end_itr; // default construction yields past-the-end

	for ( directory_iterator itr( dir_path ); itr != end_itr; ++itr )
	{
		if ( is_directory(itr->status()) )
		{
			GenerateList( *itr, base_dir_path );
		}
		else
		{
			std::string strFilePath = itr->path().generic_string();
			std::string::size_type iPos = strFilePath.find(base_dir_path.string());

			if (-1 != iPos)
			{
				strFilePath.erase(iPos, base_dir_path.generic_string().size());
			}

			std::cout << strFilePath << std::endl;
		}
	}

	return 0;
}


int GenerateList( const std::string &strPath )
{
	std::string strPathInt(strPath);
	std::replace(strPathInt.begin(), strPathInt.end(), '\\', '/');

	path dir_path(strPathInt);

	if ( !exists( dir_path ) ) 
	{
		std::cerr << "Unknown path \"" << strPath << "\"" << std::endl;
		return 1;
	}

	return GenerateList(dir_path, dir_path);
}


