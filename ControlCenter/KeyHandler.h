#pragma once
#pragma once
#include "CommandHandler.h"

class KeyHandler : public CommandHandler
{
protected:
	KeyHandler();
	void generateKey(int virtualKey, BOOL extended);

public:
	virtual ~KeyHandler();
};