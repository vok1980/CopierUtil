

#include <stdio.h>
#include <iostream>						// for std::cout
#include <string.h>


#include "help.h"
#include "generate.h"
#include "copy.h"

//#include <vector>
//#include <string>


int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if ( 0 == strcmp (argv[1] , "-g") && argc > 2 )		
		{
			GenerateList(argv[2]);
		}
		else if (0 == strcmp (argv[1] , "-c"))
		{
			if (argc < 5)
			{
				std::cerr << "Too few parameters for copy mode" << std::endl << std::endl;
				PrintHelp();
				return;
			}

			std::string strFileList	(argv[2]);
			std::string strSrcPath	(argv[3]);
			std::string strDstPath	(argv[4]);

			CopyList(strFileList, strSrcPath, strDstPath);
		}
		else
		{
			PrintHelp();
		}
	}
	else
	{
		PrintHelp();
	}


	return 0;
}


