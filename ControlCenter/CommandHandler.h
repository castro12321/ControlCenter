#pragma once

#include <string>
#include <vector>
using namespace std;

#include "Utils.h"

class CommandHandler
{
public:
	virtual ~CommandHandler()
	{}

	void handle(string sentence)
	{
		handle(split(sentence, ' '));
	}

	virtual void handle(vector<string> words) = 0;
};