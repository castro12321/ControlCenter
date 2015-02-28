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
#include "ZoomHandler.h"

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

	// Works
	static const std::regex NEW_TAB("^nowa karta");
	if (std::regex_search(sentence, result, NEW_TAB))
		return new TabHandler(TabHandler::Task::OPEN_TAB);

	// Works
	static const std::regex CLOSE_TAB("^zamknij karte");
	if (std::regex_search(sentence, result, CLOSE_TAB))
		return new TabHandler(TabHandler::Task::CLOSE_TAB);

	// Works
	static const std::regex WINDOW_CLOSE1("^zamknij aktywne"), WINDOW_CLOSE2("^zamknij okno");
	if (std::regex_search(sentence, result, WINDOW_CLOSE1)
	||  std::regex_search(sentence, result, WINDOW_CLOSE2))
		return new WindowHandler(WindowHandler::CLOSE);

	// Works
	static const std::regex WINDOW_MINIMIZE1("^minimalizuj okno"), WINDOW_MINIMIZE2("^minimalizuj");
	if (std::regex_search(sentence, result, WINDOW_MINIMIZE1)
	||  std::regex_search(sentence, result, WINDOW_MINIMIZE2))
		return new WindowHandler(WindowHandler::MINIMIZE);

	// Works
	static const std::regex WINDOW_MAXIMIZE1("^maksymalizuj okno"), WINDOW_MAXIMIZE2("^maksymalizuj");
	if (std::regex_search(sentence, result, WINDOW_MAXIMIZE1)
	||  std::regex_search(sentence, result, WINDOW_MAXIMIZE2))
		return new WindowHandler(WindowHandler::MAXIMIZE);

	static const std::regex OPEN_PROGRAM("^otworz .*");
	if (std::regex_search(sentence, result, OPEN_PROGRAM))
		return new OpenHandler();

	// Crashes if cannot find application
	static const std::regex CLOSE_PROGRAM("^zamknij .*");
	if (std::regex_search(sentence, result, CLOSE_PROGRAM))
		return new CloseHandler();

	// Works
	static const std::regex SAY_TIME1("^jaki czas"), SAY_TIME2("^czas");
	if (std::regex_search(sentence, result, SAY_TIME1)
	|| std::regex_search(sentence, result, SAY_TIME2))
		return new SayTimeHandler(SayTimeHandler::Task::SAY_TIME);

	// Works
	static const std::regex SAY_DATE1("^jaka data"), SAY_DATE2("^data");
	if (std::regex_search(sentence, result, SAY_DATE1)
	|| std::regex_search(sentence, result, SAY_DATE2))
		return new SayTimeHandler(SayTimeHandler::Task::SAY_DATE);

	// Works
	static const std::regex REFRESH("^odswiez");
	if (std::regex_search(sentence, result, REFRESH))
		return new RefreshHandler();

	static const std::regex CREATE_DIR("^(stworz|nowy) folder");
	if (std::regex_search(sentence, result, CREATE_DIR))
		return new CreateHandler(CreateHandler::COMMAND::CREATE_DIR);

	static const std::regex CREATE_FILE("^(stworz|nowy) plik");
	if (std::regex_search(sentence, result, CREATE_FILE))
		return new CreateHandler(CreateHandler::COMMAND::CREATE_FILE);

	// Works
	static const std::regex SHOW_DESKTOP("^pokaz pulpit");
	if (std::regex_search(sentence, result, SHOW_DESKTOP))
		return new ShowDesktopHandler();

	// Works
	static const std::regex ZOOM_IN("^przybliz");
	if (std::regex_search(sentence, result, ZOOM_IN))
		return new ZoomHandler(ZoomHandler::Task::ZOOM_IN);

	// Works
	static const std::regex ZOOM_OUT("^oddal");
	if (std::regex_search(sentence, result, ZOOM_OUT))
		return new ZoomHandler(ZoomHandler::Task::ZOOM_OUT);

	// Works
	static const std::regex ZOOM_RESET("^zoom reset"); // I don't know how to translate it :-(
	if (std::regex_search(sentence, result, ZOOM_RESET))
		return new ZoomHandler(ZoomHandler::Task::ZOOM_RESET);
	
	/*static const std::regex WEATHER("^weather");
	if (std::regex_search(sentence, result, WEATHER))
		return new WeatherHandler(); // Load weather info from google weather api*/

	//synthesizer.say("Sorry I don't know this command"); // Sorry, but it freezes the app :<
	std::cout << "Nothing found! Returning nullptr :<\n";
	return nullptr;
}
