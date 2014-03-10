#include "stdafx.h"
#include "KeyHandler.h"


void generateKey(int vk, BOOL bExtended)
{
	KEYBDINPUT kb = { 0 };
	INPUT   input = { 0 };
	
	// generate down
	if (bExtended)
		kb.dwFlags = KEYEVENTF_EXTENDEDKEY;
	kb.wVk = vk;
	input.type = INPUT_KEYBOARD;

	input.ki = kb;
	::SendInput(1, &input, sizeof(input));

	// generate up
	::ZeroMemory(&kb, sizeof(KEYBDINPUT));
	::ZeroMemory(&input, sizeof(INPUT));
	kb.dwFlags = KEYEVENTF_KEYUP;
	if (bExtended)
		kb.dwFlags |= KEYEVENTF_EXTENDEDKEY;

	kb.wVk     = vk;
	input.type = INPUT_KEYBOARD;
	input.ki   = kb;
	::SendInput(1, &input, sizeof(input));
}


KeyHandler::KeyHandler(int virtualKey, BOOL extended) : virtualKey(virtualKey), extended(extended)
{
}


KeyHandler::~KeyHandler()
{
}


void KeyHandler::handle(std::string, std::vector<std::string>)
{
	generateKey(virtualKey, extended);
}