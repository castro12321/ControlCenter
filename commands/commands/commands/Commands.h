#pragma once
#include <regex>
#include <vector>

class Commands
{
public:
	void recognizeCommand(std::string sentence);
	Commands();
	~Commands();
};