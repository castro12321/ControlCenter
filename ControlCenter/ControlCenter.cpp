#include "stdafx.h"
#include "ControlCenter.h"

#include "Config.h"

ControlCenter::ControlCenter()
{
}


ControlCenter::~ControlCenter()
{
	voiceRecognizer.cleanup();
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

			voiceRecorder.debugInfo();
			voiceRecorder.playBuffer();

			voiceRecorder.getBuffer().saveToFile(Config::OUT_AUDIO_FILENAME);

			std::string recognized = voiceRecognizer.recognize(Config::OUT_AUDIO_FILENAME);
			cmmndRecognizer.recognizeCommand(recognized);
			// do sth with recognized...
		}
	}
}


void ControlCenter::record()
{
	voiceRecorder.start();
	while (sf::Keyboard::isKeyPressed(Config::recordButton))
		Sleep(100);
	voiceRecorder.stop();
}