#include "stdafx.h"
#include "RefreshHandler.h"


RefreshHandler::RefreshHandler()
{
}


RefreshHandler::~RefreshHandler()
{
}


void RefreshHandler::handle(std::string sentence)
{
	generateKey(VK_F5, FALSE);
}