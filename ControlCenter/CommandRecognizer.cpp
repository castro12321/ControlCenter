#include "stdafx.h"
#include "CommandRecognizer.h"

#include "OpenHandler.h"


CommandRecognizer::CommandRecognizer()
{
}

CommandRecognizer::~CommandRecognizer()
{
}

void CommandRecognizer::fillPattern()
{
	patterns.push_back(std::regex("open .*"));
	patterns.push_back(std::regex("close .*"));
	//etc.
}

CommandHandler* CommandRecognizer::recognizeCommand(std::string sentence)
{
	fillPattern();
	std::smatch result;
	for (std::regex pattern : patterns)
		if(std::regex_search(sentence, result, pattern))
		{
			if(result[0] == "open ")
				return new OpenHandler();
			//if(result[0] == "close ")
				//return new CloseHandler(sentence);
		}

	return nullptr;
}
