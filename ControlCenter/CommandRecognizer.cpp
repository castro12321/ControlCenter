#include "stdafx.h"
#include "CommandRecognizer.h"

CommandRecognizer::CommandRecognizer()
{
}

CommandRecognizer::~CommandRecognizer()
{
}

void CommandRecognizer::fillPattern()
{
	pattern.push_back(std::regex("open *"));
	pattern.push_back(std::regex("close *"));
	//etc.
}	

CommandHandler* CommandRecognizer::recognizeCommand(std::string sentence)
{
	fillPattern();
	std::smatch result;
	for(int i=0; i<pattern.size(); i++)
		if(std::regex_search(sentence,result,pattern[i]))
		{
			if(result[0] == "open ")
			{
				sentence.erase(sentence.find("open ")); //remove "open" from command
				return NULL; //return new OpenHandler(sentence);
			}

			if(result[0] == "close ")
			{
				sentence.erase(sentence.find("close "));
				return NULL; //return new CloseHandler(sentence);
			}
		}
}

	