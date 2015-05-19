#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>

class Executive
{
public:
	using Arguments = std::vector < std::string > ;
	using Path = std::string;
	void  GetOptionsAndPatternsFromCmdLine(int argc, char* argv[]);
	void  PrepareCatalogue();

private:
	Arguments Options_;
	Arguments Patterns_;
	Path path_;

};


#endif