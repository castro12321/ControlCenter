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
	patterns.push_back(std::regex("open *"));
	patterns.push_back(std::regex("close *"));
	//etc.
}

CommandHandler* CommandRecognizer::recognizeCommand(std::string sentence)
{
	std::cout << "Trying to recognize sentence " << sentence << "\n";

	fillPattern();
	std::smatch result;
	for (std::regex pattern : patterns)
	{
		if (std::regex_search(sentence, result, pattern))
		{
			if (result[0] == "open ")
			{
				std::cout << "Recognized open command!\n";
				return new OpenHandler();
			}
			//if(result[0] == "close ")
				//return new CloseHandler(sentence);
		}
	}

	std::cout << "Nothing found! Returning nullptr :<\n";
	return nullptr;
}
