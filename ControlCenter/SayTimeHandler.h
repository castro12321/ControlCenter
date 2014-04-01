#pragma once
#include "CommandHandler.h"

class SayTimeHandler : public CommandHandler
{
public:
	enum Task {SAY_TIME, SAY_DATE};
	Task task;

	SayTimeHandler(Task value);
	virtual ~SayTimeHandler();

	void handle(std::string sentence) override;
};