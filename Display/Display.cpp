/////////////////////////////////////////////////////////////////////////////
// Display.cpp - Support display of Catalogue, duplicate files and search files //
// ver 2.2                                                                 //
// ----------------------------------------------------------------------- //
// copyright © Gautam Peri, 2012                                           //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2013                             //
// Platform:    ASUS Q550L, Core i7, Windows 8.1                           //
// Application: Summer Projects, 2012                                      //
// Author:      Gautam Peri, CST 4-284, Syracuse University                //
//              (315) 484-6562, nperi@syr.edu                             //
/////////////////////////////////////////////////////////////////////////////

#include "..\DataStore\DataStore.h"
#include "..\FileManager\FileManager.h"
#include "Display.h"
#include<iostream>
#include<string>

//Displays all items present in File Catalogue (from DataStore)
void Display::DisplayCatalogue(DataStore& store)
{
	std::cout << "\n  Displaying File Catalogue";
	std::cout << "\n ================================\n";
	int count = 0;
	DataStore::iterator iter;
	for (iter = store.begin(); iter != store.end(); iter++)
	{
		count++;
		std::string file = iter->first;
		std::cout << "\n  FileName: " << file << "\n";
		DataStore::ListOfPaths lstPaths = iter->second;
		DataStore::ListOfPaths::iterator lstIter;

		for (auto filePathList : lstPaths)
			std::cout << "\t" << (*filePathList).c_str() << "\n";

	}
	if (count == 0)
		std::cout << "No files to display in catalogue.";

	std::cout << "\n\t"  << store.StoreSize() << " files found in " << store.PathSize() << " directories.";

	std::cout << "\n\n";
}

//Displays duplicate files present in File Catalogue (from DataStore)
void Display::DisplayDuplicates(DataStore& store)
{

	std::cout << "\n  Displaying Duplicate files";
	std::cout << "\n ================================\n";

	DataStore::iterator iter;
	int count = 0;
	for (iter = store.begin(); iter != store.end(); iter++)
	{
		std::string file = iter->first;
		DataStore::ListOfPaths lstPaths = iter->second;
		if (lstPaths.size() > 1)
		{
			count++;
			std::cout << "\n  FileName: " << file << "\n";

			for (auto filePathList : lstPaths)
				std::cout << "\t" << (*filePathList).c_str() << "\n";
		}

	}

	if (count == 0)
		std::cout << "No duplicate files to display in catalogue.";

	std::cout << "\n\n";
}

//Displays list of files present which contain the search text
void Display::DisplaySearchFiles(DataStore& store, std::string searchText)
{
	std::cout << "\n  Displaying Files with Search Text \"" << searchText << "\"";
	std::cout << "\n =========================================\n";
	int count = 0;
	std::set<std::string>::iterator iter;
	for (iter = store.setBegin(); iter != store.setEnd(); iter++)
	{
		count++;
		std::string file = *iter;
		std::cout << "\n  File: \n" << file << "\n";
	}

	if (count == 0)
		std::cout << "No files found with search text " << searchText << " to display in catalogue.";

	std::cout << "\n\n";
}


#ifdef TEST_DISPLAY
int main()
{
	DataStore ds;
	Display dp;
	dp.DisplayCatalogue(ds);

	dp.DisplayDuplicates(ds);

	std::string searchText = "Search";
	dp.DisplaySearchFiles(ds, searchText);

}

#endif