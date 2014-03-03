#include "stdafx.h"
#include "CommandRecognizer.h"

#include "OpenHandler.h"
#include "CloseHandler.h"


CommandRecognizer::CommandRecognizer()
{
}

CommandRecognizer::~CommandRecognizer()
{
}

const std::regex open("open *");
const std::regex close("close *");
const std::regex show_time("show time");
const std::regex show_date("show date");
const std::regex show_desktop("show desktop");

CommandHandler* CommandRecognizer::recognizeCommand(std::string sentence)
{
	std::cout << "Trying to recognize sentence: " << sentence << "\n";

	std::smatch result;

	if(std::regex_search(sentence, result, open))
		return new OpenHandler();

	if(std::regex_search(sentence, result, close))
		return new CloseHandler();

	std::cout << "Nothing found! Returning nullptr :<\n";
	return nullptr;
}
