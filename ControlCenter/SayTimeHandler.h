#pragma once
#include "CommandHandler.h"

class SayTimeHandler : public CommandHandler
{
public:
	enum COMMAND {SAY_TIME, SAY_DATE};
	COMMAND cammand;

	SayTimeHandler(COMMAND value);
	virtual ~SayTimeHandler();

	void handle(std::string sentence) override;
};