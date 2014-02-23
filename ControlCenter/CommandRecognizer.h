#pragma once

#include <unordered_map>

class CommandHandler;

class CommandEntry
{
public:
	const std::string regex;
	const CommandHandler* const handler;
};


class CommandRecognizer
{
private:
	typedef std::string pattern;
	typedef std::vector<CommandHandler*> handlerList;
	std::unordered_map<pattern, handlerList> handlers;

public:
	CommandRecognizer();
	~CommandRecognizer();

	CommandHandler* recognizeCommand(std::string sentence);
};

