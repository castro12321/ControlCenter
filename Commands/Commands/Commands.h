#pragma once
#include <regex>
#include <vector>
#include <iostream>

class Commands
{
private:
	std::string sentence;
public:
	Commands(std::string value);
	~Commands();
	void runProgram();
};