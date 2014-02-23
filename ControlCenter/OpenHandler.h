#pragma once
#include "CommandHandler.h"


class OpenHandler : public CommandHandler
{
public:
	OpenHandler();
	virtual ~OpenHandler();

	
	void handle(vector<string> words) override;
};

