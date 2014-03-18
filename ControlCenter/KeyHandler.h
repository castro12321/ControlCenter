#pragma once
#include "CommandHandler.h"

class KeyHandler : public CommandHandler
{
protected:
	KeyHandler();
	void generateKey(int virtualKey, BOOL extended);
	void keyUp(int virtualKey, BOOL extended);
	void keyDown(int virtualKey, BOOL extended);

public:
	virtual ~KeyHandler();
};