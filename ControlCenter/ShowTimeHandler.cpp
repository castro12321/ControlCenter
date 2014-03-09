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

	std::stringstream sstream;
	std::string say;

	switch(show)
	{
		case SHOW_TIME:
			{
				std::string hour;
				std::string minute;

				if(time.wMinute < 30)
				{
					std::cout<<"1"<<std::endl;
					sstream.clear();
					sstream<<time.wHour;
					sstream>>hour;
					sstream.clear();
					sstream<<time.wMinute;
					sstream>>minute;
					say = std::string("It's ")+minute+std::string(" past ")+hour;
				}
				else
				{
					std::cout<<"2"<<std::endl;
					sstream.clear();
					sstream<<(60-time.wMinute);
					sstream>>minute;
					sstream.clear();
					sstream<<(1+time.wHour);
					sstream>>hour;
					say = std::string("It's ")+minute+std::string(" to ")+hour;
				}

				if(time.wMinute == 0)
				{
					std::cout<<"3"<<std::endl;
					sstream.clear();
					sstream<<time.wHour;
					sstream>>hour;
					say = std::string("It's ")+hour+std::string(" o'clock");
				}

				if(time.wMinute == 30)
				{
					std::cout<<"4"<<std::endl;
					sstream.clear();
					sstream<<time.wHour;
					sstream>>hour;
					say = std::string("It's half past ")+hour;
				}	
				synthesizer.say(say);
				std::cout<<say<<std::endl;
				break;
			}

		case SHOW_DATE:
			std::cout<<time.wDay<<"-"<<time.wMonth<<"-"<<time.wYear<<std::endl;
			break;
	}
}