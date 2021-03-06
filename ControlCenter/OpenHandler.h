#pragma once
#include "CommandHandler.h"

class OpenHandler : public CommandHandler
{
private:
	void runProgram(std::string name);

public:
	OpenHandler();
	virtual ~OpenHandler();
	void handle(std::string sentence) override;
};

