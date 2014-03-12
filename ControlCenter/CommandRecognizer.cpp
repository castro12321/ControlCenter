#include "stdafx.h"
#include "CommandRecognizer.h"

#include "OpenHandler.h"
#include "CloseHandler.h"
#include "SayTimeHandler.h"

CommandRecognizer::CommandRecognizer()
{
}

CommandRecognizer::~CommandRecognizer()
{
}

const std::regex open("open *");
const std::regex close("close *");
const std::regex say_time("say time");
const std::regex timee("time");
const std::regex say_date("say date");
const std::regex datee("date");
const std::regex show_desktop("show desktop");

CommandHandler* CommandRecognizer::recognizeCommand(std::string sentence)
{
	std::cout << "Trying to recognize sentence: " << sentence << "\n";

	std::smatch result;

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
