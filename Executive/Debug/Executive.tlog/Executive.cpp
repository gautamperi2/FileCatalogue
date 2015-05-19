
#include "..\DataStore\DataStore.h"
#include "..\FileManager\FileManager.h"
#include "..\Display\Display.h"
#include "Executive.h"
#include<iostream>
#include<string>


void Executive::GetOptionsAndPatternsFromCmdLine(int argc, char* argv[])
{
	if (argc <= 2)
	{
		Options_.push_back("/d");
		Patterns_.push_back("*.*");
		path_ = ".";
	}
	else
	{
		path_ = argv[1];
	}

	for (int index = 2; index < argc; index++)
	{
		int ptr = 0;
		std::string args = argv[index];
		while (args[ptr] != '\0')
		{
			if (args[ptr] == '/')
			{
				Options_.push_back(args);
				break;
			}
			ptr++;
			int length = args.size();
			if (ptr == length)
				Patterns_.push_back(args);
		}
	}

}


void Executive::PrepareCatalogue()
{
	bool IsRecursive = false;
	DataStore ds;
	FileManager Fm(path_, ds);
	Fm.addAllPatterns(Patterns_);
	Arguments::iterator argIter = std::find(Options_.begin(), Options_.end(), "/s");
	if (argIter != Options_.end())
	{
		IsRecursive = true;
	}
	Fm.search(IsRecursive);

	Display dp;
	dp.DisplayCatalogue(ds);

	argIter = std::find(Options_.begin(), Options_.end(), "/d");
	if (argIter != Options_.end())
	{
		dp.DisplayDuplicates(ds);
	}
}


#ifdef TEST_EXECUTIVE

int main(int argc, char* argv[])
{

	//ShowCommandLine(args);
	// user input: path pattern /d,/f,/s

	Executive obj;
	obj.GetOptionsAndPatternsFromCmdLine(argc, argv);
	obj.PrepareCatalogue();	
}

#endif