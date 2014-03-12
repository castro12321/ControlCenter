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


void OpenHandler::runProgram(std::string name)
{
	std::vector <std::string> programs = Utils::getDeclaredApplications();
	std::wstring programName = std::wstring(name.begin(), name.end()) + L".lnk";

	for (std::string program : programs)
		if (program == std::string(name + ".lnk"))
		{
			ShellExecute(NULL, L"open", programName.c_str(), NULL, L"programs", SW_SHOWDEFAULT);
			return;
		}
	
	synthesizer.say("I didn't find program");
}

void OpenHandler::handle(std::string sentence)
{
	std::vector<std::string> words = Utils::split(sentence, ' ', 1);
	if(words.size() > 1)
	{
		std::string program = words.at(1);
		runProgram(program);
	}
	else
		synthesizer.say("I didn't find program");
}