#pragma once
#include <regex>
#include <vector>
#include <unordered_map>

class CommandHandler;

class CommandRecognizer
{
public:
	CommandHandler* recognizeCommand(std::string sentence);
	CommandRecognizer();
	~CommandRecognizer();
};

