

#include <stdio.h>
#include <string.h>

//#include <vector>
//#include <string>


int main(int argc, char *argv[])
{
//	std::vector<std::string> aParams;

	//while (--argc > 0)
	//	printf("%s \n", argv[argc]);

	if (argc > 1)
	{
		if ( 0 == strcmp (argv[1] , "-g")  )		
		{
			GenerateList();
		}
		else if (0 == strcmp (argv[1] , "-c"))
		{
			CopyList();
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


