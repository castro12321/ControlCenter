#include "stdafx.h"
#include "CreateHandler.h"
#include <WinBase.h>

CreateHandler::CreateHandler(COMMAND command) : command(command)
{
}


CreateHandler::~CreateHandler()
{
}


std::string getInput(std::string header, std::string message)
{
	// TODO: add QT
	/*
	bool ok;
	QString text = QInputDialog::getText(header, message, 
		QLineEdit::Normal, QString::null, &ok, this);

	if (ok && !text.isEmpty())
		return text;
	return "";
	*/
	std::string text;
	std::cin >> text;
	return text;
}


std::string currentExplorerDirectory()
{
	// TODO: helpful links?
	// http://blogs.msdn.com/b/oldnewthing/archive/2004/07/20/188696.aspx
	// http://msdn.microsoft.com/en-us/library/bb773974%28v=vs.85%29.aspx
	// http://www.dreamincode.net/forums/topic/264754-how-to-get-active-windows-explorer-directory/
	return "";
}


void createFile()
{
	std::string   name = getInput("Create directory", "Enter directory name:");
	std::wstring wname = std::wstring(name.begin(), name.end());
	HANDLE file = CreateFile(wname.c_str(), 0, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
	CloseHandle(file);
}


void createDir()
{
	std::string   name = getInput("Create directory", "Enter directory name:");
	std::wstring wname = std::wstring(name.begin(), name.end());
	CreateDirectory(wname.c_str(), NULL);
}


void CreateHandler::handle(std::string sentence)
{
	switch (command)
	{
	case COMMAND::CREATE_DIR:
		createDir();
		break;
	case COMMAND::CREATE_FILE:
		createFile();
		break;
	}
}