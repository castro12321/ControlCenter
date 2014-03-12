#pragma once
#include "CommandHandler.h"

class WindowHandler : public CommandHandler
{
public:
	enum Task { MINIMIZE, MAXIMIZE, CLOSE } task;

	WindowHandler(Task task);
	~WindowHandler();

	void handle(std::string sentence) override;
};

