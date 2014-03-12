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

	virtual void handle(std::string sentence) = 0;
};