#pragma once
#include "CommandHandler.h"

class ShowDesktopHandler : public CommandHandler
{
public:
	ShowDesktopHandler();
	virtual ~ShowDesktopHandler();
	void handle(std::string sentence) override;
};