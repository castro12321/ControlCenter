#pragma once
#include <regex>
#include <vector>
#include <unordered_map>

#include "SpeechSynthesizer.h"

class CommandHandler;

class CommandRecognizer
{
private:
	SpeechSynthesizer synthesizer;

public:
	CommandHandler* recognizeCommand(std::string sentence);
	CommandRecognizer();
	~CommandRecognizer();
};

