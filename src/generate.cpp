
#include <iostream>						// for std::cout
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
			std::wstring strFilePath = itr->path().generic_wstring();
			std::wstring::size_type iPos = strFilePath.find(base_dir_path.generic_wstring());
			strFilePath.erase(iPos, base_dir_path.generic_wstring().size());

			std::cout << strFilePath << "\n";
		}
	}

	return 0;
}


int GenerateList( const std::string &strPath )
{
	path dir_path(strPath);

	if ( !exists( dir_path ) ) 
	{
		std::cerr << "Unknown path \"" << strPath << "\"";
		return 1;
	}

	return GenerateList(dir_path, dir_path);
}


