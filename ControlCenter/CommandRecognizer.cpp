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

static const std::regex open("open *");
static const std::regex close("close *");
static const std::regex say_time("say time");
static const std::regex timee("time");
static const std::regex say_date("say date");
static const std::regex datee("date");
static const std::regex show_desktop("show desktop");

CommandHandler* CommandRecognizer::recognizeCommand(std::string sentence)
{
	std::cout << "Trying to recognize sentence: " << sentence << "\n";

	std::smatch result;

	
	static const std::regex WINDOW_CLOSE1("^close (active|current)"), WINDOW_CLOSE2("^window close");
	if (std::regex_search(sentence, result, WINDOW_CLOSE1)
	||  std::regex_search(sentence, result, WINDOW_CLOSE2))
		return new WindowHandler(WindowHandler::CLOSE);

	static const std::regex WINDOW_MINIMIZE("^window minimize");
	if (std::regex_search(sentence, result, WINDOW_MINIMIZE))
		return new WindowHandler(WindowHandler::MINIMIZE);

	static const std::regex WINDOW_MAXIMIZE("^window maximize");
	if (std::regex_search(sentence, result, WINDOW_MAXIMIZE))
		return new WindowHandler(WindowHandler::MAXIMIZE);


	if(std::regex_search(sentence, result, open))
		return new OpenHandler();

	if(std::regex_search(sentence, result, close))
		return new CloseHandler();

	if(std::regex_search(sentence, result, say_time) || std::regex_search(sentence, result, timee))
		return new SayTimeHandler(SayTimeHandler::COMMAND::SAY_TIME);

	if(std::regex_search(sentence, result, say_date) || std::regex_search(sentence, result, datee))
		return new SayTimeHandler(SayTimeHandler::COMMAND::SAY_DATE);

	synthesizer.say("Sorry I don't know this command");
	//std::cout << "Nothing found! Returning nullptr :<\n";
	return nullptr;
}
