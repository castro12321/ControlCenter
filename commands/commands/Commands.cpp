#include <iostream>
#include "Commands.h"

Commands::Commands()
{
}

Commands::~Commands()
{
}

void Commands::recognizeCommand(std::string sentence)
{
	std::cout << "Trying to recognize sentence: " << sentence << "\n";

	std::smatch result;

	static const std::regex CLOSE_TAB("^close tab");
	if (std::regex_search(sentence, result, CLOSE_TAB))
		system("tab_handler.exe close");

	static const std::regex NEW_TAB("^new tab");
	if (std::regex_search(sentence, result, NEW_TAB))
		system("tab_handler.exe new");

	static const std::regex WINDOW_CLOSE1("^close (active|current)"), WINDOW_CLOSE2("^window close");
	if (std::regex_search(sentence, result, WINDOW_CLOSE1)
		|| std::regex_search(sentence, result, WINDOW_CLOSE2))
		system("window_handler.exe close");
	
	static const std::regex WINDOW_MINIMIZE1("^window minimize"), WINDOW_MINIMIZE2("^minimize");
	if (std::regex_search(sentence, result, WINDOW_MINIMIZE1)
		|| std::regex_search(sentence, result, WINDOW_MINIMIZE2))
		system("window_handler.exe minimize");

	static const std::regex WINDOW_MAXIMIZE1("^window maximize"), WINDOW_MAXIMIZE2("^maximize");
	if (std::regex_search(sentence, result, WINDOW_MAXIMIZE1)
		|| std::regex_search(sentence, result, WINDOW_MAXIMIZE2))
		system("window_handler.exe maximize");

	static const std::regex OPEN_PROGRAM("^open .*");
	if (std::regex_search(sentence, result, OPEN_PROGRAM))
	{
		std::string parameter = std::string("open_handler.exe ") + sentence;
		system(parameter.c_str());
	}

	static const std::regex CLOSE_PROGRAM("^close .*");
	if (std::regex_search(sentence, result, CLOSE_PROGRAM))
	{
		std::string parameter = std::string("open_handler.exe ") + sentence;
		system(parameter.c_str());
	}

	static const std::regex SAY_TIME1("^say time"), SAY_TIME2("^time");
	if (std::regex_search(sentence, result, SAY_TIME1)
		|| std::regex_search(sentence, result, SAY_TIME2))
		system("say_time_handler.exe time");

	static const std::regex SAY_DATE1("^say date"), SAY_DATE2("^date");
	if (std::regex_search(sentence, result, SAY_DATE1)
		|| std::regex_search(sentence, result, SAY_DATE2))
		system("say_time_handler.exe date");

	static const std::regex REFRESH("^refresh");
	if (std::regex_search(sentence, result, REFRESH))
		system("refresh.exe");

	static const std::regex CREATE_DIR("^(create|new) directory");
	if (std::regex_search(sentence, result, CREATE_DIR))
		system("create_handler.exe dir");

	static const std::regex CREATE_FILE("^(create|new) file");
	if (std::regex_search(sentence, result, CREATE_FILE))
		system("create_handler.exe file");

	static const std::regex SHOW_DESKTOP("^show desktop");
	if (std::regex_search(sentence, result, SHOW_DESKTOP))
		system("show_desktop_handler.exe");

	static const std::regex ZOOM_IN("^zoom in");
	if (std::regex_search(sentence, result, ZOOM_IN))
		system("zoom_handler.exe in");

	static const std::regex ZOOM_OUT("^zoom out");
	if (std::regex_search(sentence, result, ZOOM_OUT))
		system("zoom_handler.exe out");

	static const std::regex ZOOM_RESET("^zoom reset");
	if (std::regex_search(sentence, result, ZOOM_RESET))
		system("zoom_handler.exe reset");

	//synthesizer.say("Sorry I don't know this command"); // Sorry, but it freezes the app :<
	std::cout << "Nothing found! Returning nullptr :<\n";
}