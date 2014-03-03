#include "stdafx.h"
#include "ShowTimeHandler.h"

ShowTimeHandler::ShowTimeHandler(SHOW value)
{
	show = value;
}

ShowTimeHandler::~ShowTimeHandler()
{
}

void ShowTimeHandler::handle(std::string sentence, std::vector<std::string> words)
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	switch(show)
	{
		case SHOW_TIME:
			std::cout<<time.wHour<<":"<<time.wMinute<<":"<<time.wSecond<<std::endl;
			break;

		case SHOW_DATE:
			std::cout<<time.wDay<<"-"<<time.wMonth<<"-"<<time.wYear<<std::endl;
			break;
	}
}