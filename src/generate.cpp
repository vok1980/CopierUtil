
#include "boost/filesystem.hpp"			// includes all needed Boost.Filesystem declarations
#include <iostream>						// for std::cout
using namespace boost::filesystem;      // for ease of tutorial presentation;
										//  a namespace alias is preferred practice in real code



int GenerateList( const boost::filesystem::path &dir_path )
{
	directory_iterator end_itr; // default construction yields past-the-end

	for ( directory_iterator itr( dir_path ); itr != end_itr; ++itr )
	{
		if ( is_directory(itr->status()) )
		{
			GenerateList( *itr );
		}
		else
		{
			std::cout << itr->path().generic_string() << "\n";
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

	return GenerateList(dir_path);
}


