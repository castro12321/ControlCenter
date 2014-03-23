#pragma once
#include "KeyHandler.h"

class ZoomHandler : public KeyHandler
{
public:
	enum Task {ZOOM_IN, ZOOM_OUT, ZOOM_RESET};
	Task task;

	ZoomHandler(Task value);
	~ZoomHandler();
	void handle(std::string sentence) override;
};