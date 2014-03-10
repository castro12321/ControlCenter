#include "stdafx.h"
#include "SayTimeHandler.h"

SayTimeHandler::SayTimeHandler(COMMAND value)
{
	cammand = value;
}

SayTimeHandler::~SayTimeHandler()
{
}

void SayTimeHandler::handle(std::string sentence, std::vector<std::string> words)
{
	SYSTEMTIME time;
	GetLocalTime(&time);

	std::stringstream sstream;
	sstream.clear();
	std::string say;

	switch(cammand)
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

				switch(time.wDay)
				{
					case 1: day = "Today is the first of "; break;
					case 2: day = "Today is the second of "; break;
					case 3: day = "Today is the third of "; break;
					case 4: day = "Today is the fourth of "; break;
					case 5: day = "Today is the fifth of "; break;
					case 6: day = "Today is the sixth of "; break;
					case 7: day	= "Today is the seventh of "; break;
					case 8: day = "Today is the eighth of "; break;
					case 9: day = "Today is the ninth of "; break;
					case 10: day = "Today is the tenth of "; break;
					case 11: day = "Today is the eleventh of "; break;
					case 12: day = "Today is the twelfth of "; break;
					case 13: day = "Today is the thirteenth of "; break;
					case 14: day = "Today is the fourteenth of "; break;
					case 15: day = "Today is the fifteenth of "; break;
					case 16: day = "Today is the sixteenth of "; break;
					case 17: day = "Today is the seventeenth of "; break;
					case 18: day = "Today is the eighteenth of "; break;
					case 19: day = "Today is the nineteenth of "; break;
					case 20: day = "Today is the twentieth of "; break;
					case 21: day = "Today is the twenty-first of "; break;
					case 22: day = "Today is the twenty-second of "; break;
					case 23: day = "Today is the twenty-third of "; break;
					case 24: day = "Today is the twenty-fourth of "; break;
					case 25: day = "Today is the twenty-fifth of "; break;
					case 26: day = "Today is the twenty-sixth of "; break;
					case 27: day = "Today is the twenty-seventh of "; break;
					case 28: day = "Today is the twenty-eighth of "; break;
					case 29: day = "Today is the twenty-ninth of "; break;
					case 30: day = "Today is the thirtieth of "; break;
					case 31: day = "Today is the thirty-first of "; break;
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

				say = day+month;
				synthesizer.say(say);
				break;
			}
	}
}