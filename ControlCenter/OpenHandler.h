#pragma once
#include "CommandHandler.h"


class OpenHandler : public CommandHandler
{
public:
	OpenHandler();
	virtual ~OpenHandler();

	
	void handle(std::vector<std::string> words) override;
};

