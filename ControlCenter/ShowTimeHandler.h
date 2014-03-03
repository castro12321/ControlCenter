#pragma once
#include "CommandHandler.h"

class ShowTimeHandler : public CommandHandler
{
public:
	enum SHOW {SHOW_TIME, SHOW_DATE};
	SHOW show;

	ShowTimeHandler(SHOW value);
	virtual ~ShowTimeHandler();

	void handle(std::string sentence, std::vector<std::string> words) override;
};