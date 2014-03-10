#pragma once
#pragma once
#include "CommandHandler.h"

class KeyHandler : public CommandHandler
{
private:
	const int  virtualKey;
	const BOOL extended;

protected:
	KeyHandler(int virtualKey, BOOL extended);

public:
	virtual ~KeyHandler();
	void handle(std::string, std::vector<std::string>) override;
};