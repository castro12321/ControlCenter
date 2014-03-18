#include "stdafx.h"
#include "CommandRecognizer.h"

#include "WindowHandler.h"
#include "OpenHandler.h"
#include "CloseHandler.h"
#include "SayTimeHandler.h"
#include "RefreshHandler.h"
#include "CreateHandler.h"
#include "ShowDesktopHandler.h"
#include "TabHandler.h"

CommandRecognizer::CommandRecognizer()
{
}

CommandRecognizer::~CommandRecognizer()
{
}

CommandHandler* CommandRecognizer::recognizeCommand(std::string sentence)
{
	std::cout << "Trying to recognize sentence: " << sentence << "\n";

	std::smatch result;

	static const std::regex NEW_TAB("^new tab");
	if (std::regex_search(sentence, result, NEW_TAB))
		return new TabHandler(TabHandler::Task::OPEN_TAB);

	static const std::regex CLOSE_TAB("^close tab");
	if (std::regex_search(sentence, result, CLOSE_TAB))
		return new TabHandler(TabHandler::Task::CLOSE_TAB);

	static const std::regex WINDOW_CLOSE1("^close (active|current)"), WINDOW_CLOSE2("^window close");
	if (std::regex_search(sentence, result, WINDOW_CLOSE1)
	||  std::regex_search(sentence, result, WINDOW_CLOSE2))
		return new WindowHandler(WindowHandler::CLOSE);

	static const std::regex WINDOW_MINIMIZE1("^window minimize"), WINDOW_MINIMIZE2("^minimize");
	if (std::regex_search(sentence, result, WINDOW_MINIMIZE1)
	||  std::regex_search(sentence, result, WINDOW_MINIMIZE2))
		return new WindowHandler(WindowHandler::MINIMIZE);

	static const std::regex WINDOW_MAXIMIZE1("^window maximize"), WINDOW_MAXIMIZE2("^maximize");
	if (std::regex_search(sentence, result, WINDOW_MAXIMIZE1)
	||  std::regex_search(sentence, result, WINDOW_MAXIMIZE2))
		return new WindowHandler(WindowHandler::MAXIMIZE);

	static const std::regex OPEN_PROGRAM("^open .*");
	if (std::regex_search(sentence, result, OPEN_PROGRAM))
		return new OpenHandler();

	static const std::regex CLOSE_PROGRAM("^close .*");
	if (std::regex_search(sentence, result, CLOSE_PROGRAM))
		return new CloseHandler();

	static const std::regex SAY_TIME1("^say time"), SAY_TIME2("^time");
	if (std::regex_search(sentence, result, SAY_TIME1)
	|| std::regex_search(sentence, result, SAY_TIME2))
		return new SayTimeHandler(SayTimeHandler::Task::SAY_TIME);

	static const std::regex SAY_DATE1("^say date"), SAY_DATE2("^date");
	if (std::regex_search(sentence, result, SAY_DATE1)
	|| std::regex_search(sentence, result, SAY_DATE2))
		return new SayTimeHandler(SayTimeHandler::Task::SAY_DATE);

	static const std::regex REFRESH("^refresh");
	if (std::regex_search(sentence, result, REFRESH))
		return new RefreshHandler();

	static const std::regex CREATE_DIR("^(create|new) directory");
	if (std::regex_search(sentence, result, CREATE_DIR))
		return new CreateHandler(CreateHandler::COMMAND::CREATE_DIR);

	static const std::regex CREATE_FILE("^(create|new) file");
	if (std::regex_search(sentence, result, CREATE_FILE))
		return new CreateHandler(CreateHandler::COMMAND::CREATE_FILE);

	static const std::regex SHOW_DESKTOP("^show desktop");
	if (std::regex_search(sentence, result, SHOW_DESKTOP))
		return new ShowDesktopHandler();

	//synthesizer.say("Sorry I don't know this command"); // Sorry, but it freezes the app :<
	std::cout << "Nothing found! Returning nullptr :<\n";
	return nullptr;
}
