#pragma once
#include <Windows.h>

class WindowHandler
{
public:
	enum Task { MINIMIZE, MAXIMIZE, CLOSE } task;

	WindowHandler(Task task);
	~WindowHandler();

	void windowHandler();
};