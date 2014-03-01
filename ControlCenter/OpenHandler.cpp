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

	std::string From = "C:/Users/Piotr Bielski/Documents/Programowanie/Projekty/ControlCenter/ControlCenter/programs/"+name+".lnk";
	// ^^ path to program
	std::wstring To(From.begin(), From.end());
	LPCTSTR Last = To.c_str();

	for(std::string program : programs)
		if(program == std::string(name+".lnk"))
			ShellExecute(NULL, L"open",Last, NULL, NULL, SW_SHOWDEFAULT);
}

void OpenHandler::handle(std::vector<std::string> words)
{
	std::string program = words.at(1);
	databasePrograms();
	runProgram(program);
}