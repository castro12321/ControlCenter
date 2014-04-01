#pragma once
#include "KeyHandler.h"

class TabHandler : public KeyHandler
{
public:
	enum Task {OPEN_TAB, CLOSE_TAB};
	Task task;

	TabHandler(Task value);
	~TabHandler();
	void handle(std::string sentence) override;
};