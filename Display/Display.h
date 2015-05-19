#ifndef DISPLAY_H
#define DISPLAY_H
/////////////////////////////////////////////////////////////////////////////
// Display.h - Support display of Catalogue, duplicate files and search files //
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
/*
* Module Operations:
* ==================
* This module provides display of DataStore elements. 
* It supports the displaying of file catalogue from DataStore,
* display of duplicate files from catalogue and files having a given
* search text 
*
* Public Interface:
* =================
* DataStore ds;
* Display dp;
*	dp.DisplayCatalogue(ds);
*	dp.DisplayDuplicates(ds);
*
*	std::string searchText = "Search";
*	dp.DisplaySearchFiles(ds,searchText);
*
* Required Files:
* ===============
* Display.h, Display.cpp
*
* Build Command:
* ==============
* devenv FileCatalogue.sln /rebuild Debug
*
* Maintenance History:
* ====================

* ver 1.0 : 12 Feb 15
* - first release
*/



#include<iostream>
#include<string>

class Display
{

public:
	void DisplayCatalogue(DataStore& store);
	void DisplayDuplicates(DataStore& store);
	void DisplaySearchFiles(DataStore& store, std::string searchText);

};



#endif