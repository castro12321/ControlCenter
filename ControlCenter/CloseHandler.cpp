#include "stdafx.h"
#include "CloseHandler.h"
#include <Windows.h>



CloseHandler::CloseHandler()
{
}


CloseHandler::~CloseHandler()
{
}


void CloseHandler::handle(std::string sentence, std::vector<std::string> words)
{
	std::string program = words.at(1);
	
}