#pragma once
#include "KeyHandler.h"

class RefreshHandler : public KeyHandler
{
public:
	RefreshHandler();
	virtual ~RefreshHandler();
	void handle(std::string sentence) override;
};

