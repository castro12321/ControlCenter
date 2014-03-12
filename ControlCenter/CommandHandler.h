#pragma once

#include <string>
#include <vector>

#include "Utils.h"
#include "SpeechSynthesizer.h"

class CommandHandler
{
protected:
	SpeechSynthesizer synthesizer;

public:
	virtual ~CommandHandler()
	{}

	void handle(std::string sentence)
	{
		handle(sentence, Utils::split(sentence, ' '));
	}

	virtual void handle(std::string sentence, std::vector<std::string> words) = 0;
};