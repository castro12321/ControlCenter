#pragma once
#include "CommandHandler.h"

class CloseHandler : public CommandHandler
{
public:
	CloseHandler();
	virtual ~CloseHandler();
	void handle(std::string sentence, std::vector<std::string> words) override;
};

