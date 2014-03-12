#include "stdafx.h"
#include "CommandRecognizer.h"

#include "WindowHandler.h"
#include "OpenHandler.h"
#include "CloseHandler.h"
#include "SayTimeHandler.h"

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
	if (std::regex_search(sentence, result, SAY_TIME1) || std::regex_search(sentence, result, SAY_TIME2))
		return new SayTimeHandler(SayTimeHandler::COMMAND::SAY_TIME);

	static const std::regex SAY_DATE1("^say date"), SAY_DATE2("^date");
	if (std::regex_search(sentence, result, SAY_DATE1) || std::regex_search(sentence, result, SAY_DATE2))
		return new SayTimeHandler(SayTimeHandler::COMMAND::SAY_DATE);

	static const std::regex SHOW_DESKTOP("^show desktop");


	//synthesizer.say("Sorry I don't know this command"); // Sorry, but it freezes the app :<
	std::cout << "Nothing found! Returning nullptr :<\n";
	return nullptr;
}
