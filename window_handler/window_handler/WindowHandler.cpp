#include "WindowHandler.h"


WindowHandler::WindowHandler(Task task) : task(task)
{
}


WindowHandler::~WindowHandler()
{
}


void WindowHandler::windowHandler()
{
	HWND foregroundWindow = GetForegroundWindow();

	switch (task)
	{
	case Task::CLOSE:
		PostMessage(foregroundWindow, WM_CLOSE, 0, 0);
		break;

	case Task::MAXIMIZE:
		ShowWindow(foregroundWindow, SW_MAXIMIZE);
		break;

	case Task::MINIMIZE:
		ShowWindow(foregroundWindow, SW_MINIMIZE);
		break;
	}
}