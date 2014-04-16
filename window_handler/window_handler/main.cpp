#include "WindowHandler.h"

void main(int argc, char * argv[])
{
	if (argc > 1)
	{
		if (argv[2] == "close")
		{
			WindowHandler window(WindowHandler::CLOSE);
			window.windowHandler();
		}

		if (argv[2] == "maximize")
		{
			WindowHandler window(WindowHandler::MAXIMIZE);
			window.windowHandler();
		}
			

		if (argv[2] == "minimize")
		{
			WindowHandler window(WindowHandler::MINIMIZE);
			window.windowHandler();
		}
			
	}
	
}