#include "stdafx.h"
#include "SayTimeHandler.h"

SayTimeHandler::SayTimeHandler(Task value)
{
	task = value;
}

SayTimeHandler::~SayTimeHandler()
{
}

void SayTimeHandler::handle(std::string sentence)
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	std::stringstream sstream;
	sstream.clear();
	std::string say;

	switch(task)
	{
		case SAY_TIME:
			{
				std::string hour;
				std::string minute;

				sstream<<time.wHour;
				sstream>>hour;

				sstream.clear();

				sstream<<time.wMinute;
				sstream>>minute;

				say = std::string("<context id='time'>It's ")+hour+std::string(":")+minute+std::string("</context>");
				synthesizer.say(say);
				break;
			}

		case SAY_DATE:
			{
				std::string month;
				std::string day;
				std::string today("Today is ");

				switch(time.wDay)
				{
					case 1: day = "the first of "; break;
					case 2: day = "the second of "; break;
					case 3: day = "the third of "; break;
					case 4: day = "the fourth of "; break;
					case 5: day = "the fifth of "; break;
					case 6: day = "the sixth of "; break;
					case 7: day	= "the seventh of "; break;
					case 8: day = "the eighth of "; break;
					case 9: day = "the ninth of "; break;
					case 10: day = "the tenth of "; break;
					case 11: day = "the eleventh of "; break;
					case 12: day = "the twelfth of "; break;
					case 13: day = "the thirteenth of "; break;
					case 14: day = "the fourteenth of "; break;
					case 15: day = "the fifteenth of "; break;
					case 16: day = "the sixteenth of "; break;
					case 17: day = "the seventeenth of "; break;
					case 18: day = "the eighteenth of "; break;
					case 19: day = "the nineteenth of "; break;
					case 20: day = "the twentieth of "; break;
					case 21: day = "the twenty-first of "; break;
					case 22: day = "the twenty-second of "; break;
					case 23: day = "the twenty-third of "; break;
					case 24: day = "the twenty-fourth of "; break;
					case 25: day = "the twenty-fifth of "; break;
					case 26: day = "the twenty-sixth of "; break;
					case 27: day = "the twenty-seventh of "; break;
					case 28: day = "the twenty-eighth of "; break;
					case 29: day = "the twenty-ninth of "; break;
					case 30: day = "the thirtieth of "; break;
					case 31: day = "the thirty-first of "; break;
				}

				switch(time.wMonth)
				{
					case 1: month = "January"; break;
					case 2: month = "February"; break;
					case 3: month = "March"; break;
					case 4: month = "April"; break;
					case 5: month = "May"; break;
					case 6: month = "June"; break;
					case 7: month = "July"; break;
					case 8: month = "August"; break;
					case 9: month = "September"; break;
					case 10: month = "October"; break;
					case 11: month = "November"; break;
					case 12: month = "December"; break;
				}		

				say = today+day+month;
				synthesizer.say(say);
				break;
			}
	}
}