#pragma once
#include "CommandHandler.h"

class OpenHandler : public CommandHandler
{
private:
	std::vector <std::string> programs;
	void databasePrograms();
	void runProgram(std::string name);

public:
	OpenHandler();
	virtual ~OpenHandler();
	void handle(std::string sentence, std::vector<std::string> words) override;
};

