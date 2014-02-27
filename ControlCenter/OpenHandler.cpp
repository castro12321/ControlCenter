#include "stdafx.h"
#include "OpenHandler.h"


OpenHandler::OpenHandler()
{
}


OpenHandler::~OpenHandler()
{
}

// word0   word1
// "open <program>"
void OpenHandler::handle(std::vector<std::string> words)
{
	std::string program = words.at(1);
	// TODO: open program ;)
}