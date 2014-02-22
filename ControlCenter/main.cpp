// ControlCenter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "ControlCenter.h"


int main(int argc, char *argv[])
{
	std::cout << "Initializing Control Center\n";
	ControlCenter app;
	std::cout << "Initialized Control Center\n";
	app.run();
	return 0;
}