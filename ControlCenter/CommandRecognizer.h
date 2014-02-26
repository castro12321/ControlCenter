#pragma once
#include <regex>
#include <vector>
#include <unordered_map>

class CommandHandler;

class CommandRecognizer
{
private:
	std::vector <std::regex> pattern;
	void fillPattern();

public:
	CommandHandler* recognizeCommand(std::string sentence);
	CommandRecognizer();
	~CommandRecognizer();
};

