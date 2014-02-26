#include "stdafx.h"
#include "ControlCenter.h"

#include "Config.h"

ControlCenter::ControlCenter()
{
}


ControlCenter::~ControlCenter()
{
	recognizer.cleanup();
}


void ControlCenter::run()
{
	while (true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return;

		if (sf::Keyboard::isKeyPressed(Config::recordButton))
		{
			record();

			recorder.debugInfo();
			recorder.playBuffer();

			recorder.getBuffer().saveToFile(Config::OUT_AUDIO_FILENAME);

			std::string recognized = recognizer.recognize(Config::OUT_AUDIO_FILENAME); 
			command.recognizeCommand(recognized);
			// do sth with recognized...
		}
	}
}


void ControlCenter::record()
{
	recorder.start();
	while (sf::Keyboard::isKeyPressed(Config::recordButton))
		Sleep(100);
	recorder.stop();
}