#pragma once
#include "CommandHandler.h"

class CreateHandler : public CommandHandler
{
public:
	enum COMMAND { CREATE_DIR, CREATE_FILE };
	COMMAND command;

	CreateHandler(COMMAND command);
	~CreateHandler();

	void handle(std::string sentence) override;
};

