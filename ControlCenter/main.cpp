// ControlCenter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "ControlCenter.h"
#include "WebRequestListener.h"


int main(int argc, char *argv[])
{
	std::cout << "Starting web listener\n";
	WebRequestListener listener;
	while (true)
	{
		std::cout << "query listener for a request\n";
		std::string request = listener.nextSentence();
		if (request != "")
		{
			std::cout << "Got request!\n--- REQUEST ---\n" << request << "\n\n";
			// Handle it...
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