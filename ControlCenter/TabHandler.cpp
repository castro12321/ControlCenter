#include "stdafx.h"
#include "TabHandler.h"

TabHandler::TabHandler(Task value)
{
	task = value;
}

TabHandler::~TabHandler()
{
}

void TabHandler::handle(std::string sentence)
{
	switch(task)
	{
		case OPEN_TAB:
		{
			keyDown(VK_CONTROL, FALSE);
			keyDown(0x54, FALSE);

			keyUp(VK_CONTROL, FALSE);
			keyUp(0x54, FALSE);
			break;
		}

		case CLOSE_TAB:
		{
			keyDown(VK_CONTROL, FALSE);
			keyDown(0x57, FALSE);

			keyUp(VK_CONTROL, FALSE);
			keyUp(0x57, FALSE);
			break;
		}
	}
}