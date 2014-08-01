// ControlCenter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utils.h"

#include "ControlCenter.h"
#include "WebRequestListener.h"
#include "CommandRecognizer.h"
#include "CommandHandler.h"


int main(int argc, char *argv[])
{
	WebRequestListener listener;
	CommandRecognizer cmmndRecognizer;

	std::cout << "Starting web listener\n";
	while (true)
	{
		std::cout << "query listener for a request\n";
		std::string request = listener.nextSentence();
		if (request != "")
		{
			request = Utils::removeSpaceBefore(request);
			std::cout << "Got request!\n--- REQUEST ---\n" << request << "\n\n";
			
			CommandHandler* handler = cmmndRecognizer.recognizeCommand(request);

			if (handler != nullptr)
				handler->handle(request);
		}
	}

	std::cin.get();
	return 0;

	/*
	SpeechSynthesizer synthesizer;

	std::cout << "Initializing Control Center\n";
	ControlCenter app;
	std::cout << "Initialized Control Center\n";
	synthesizer.say("I am ready");
	app.run();
	return 0;
	*/
}