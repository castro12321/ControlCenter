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
				sentence.erase(sentence.begin(),sentence.begin()+5); //remove "open" from command
				return NULL; //return new OpenHandler(sentence);
			}

			if(result[0] == "close ")
			{
				sentence.erase(sentence.begin(),sentence.begin()+6);
				return NULL; //return new CloseHandler(sentence);
			}
		}
}

	