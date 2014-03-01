#include "stdafx.h"
#include "OpenHandler.h"
#include <fstream>
#include <dirent.h>

OpenHandler::OpenHandler()
{
}


OpenHandler::~OpenHandler()
{
}

void OpenHandler::databasePrograms()
{
	DIR* dir = opendir("programs/");
	dirent* ent;
	if(dir != NULL)
		while ((ent = readdir (dir)) != NULL) 
		{
			programs.push_back(ent->d_name);
		}
	else
		std::cout<<"could not open directory"<<std::endl;

	closedir(dir);
}

void OpenHandler::runProgram(std::string name)
{
	databasePrograms();

	for(int i=0; i<programs.size(); i++)
		if(programs[i] == std::string(name+".lnk"))
		{
			ShellExecute(NULL, L"open", L"\"C:\\Documents and Settings\\All Users\\Desktop\\Aventail VPN Connection.lnk\"", NULL, NULL, SW_SHOWDEFAULT);
		}
}

// word0   word1
// "open <program>"

void OpenHandler::handle(std::vector<std::string> words)
{
	std::string program = words.at(1);

	// TODO: open program ;)
}