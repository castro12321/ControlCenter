// ControlCenter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "ControlCenter.h"
#include "SpeechSynthesizer.h"


int main(int argc, char *argv[])
{
	SpeechSynthesizer synthesizer;

	std::cout << "Initializing Control Center\n";
	ControlCenter app;
	std::cout << "Initialized Control Center\n";
	synthesizer.say("I am ready");
	app.run();
	return 0;
}