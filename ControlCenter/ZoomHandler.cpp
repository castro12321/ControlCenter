#include "stdafx.h"
#include "ZoomHandler.h"

ZoomHandler::ZoomHandler(Task value)
{
	task = value;
}

ZoomHandler::~ZoomHandler()
{
}

void ZoomHandler::handle(std::string sentence)
{
	switch(task)
	{
	case ZOOM_IN:
		{
			keyDown(VK_CONTROL, NULL);
			keyDown(VK_ADD, NULL);

			keyUp(VK_CONTROL, NULL);
			keyUp(VK_ADD, NULL);
			break;
		}

	case ZOOM_OUT:
		{
			keyDown(VK_CONTROL, NULL);
			keyDown(VK_SUBTRACT, NULL);

			keyUp(VK_CONTROL, NULL);
			keyUp(VK_SUBTRACT, NULL);
			break;
		}
	
	case ZOOM_RESET:
		{
			keyDown(VK_CONTROL, NULL);
			keyDown(VK_NUMPAD0, NULL);

			keyUp(VK_CONTROL, NULL);
			keyUp(VK_NUMPAD0, NULL);
			break;
		}
	}
}