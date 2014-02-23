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
void OpenHandler::handle(vector<string> words)
{
	string program = words.at(1);
	// TODO: open program ;)
}