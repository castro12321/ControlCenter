#include "stdafx.h"
#include "Recorder.h"

#include <Windows.h>

Recorder::Recorder()
{
	// first check if an input audio device is available on the system
	if (!sf::SoundBufferRecorder::isAvailable())
	{
		// error: audio capture is not available on this system
		throw "audio capture is not available on this system";
	}

	// create the recorder
	sf::SoundBufferRecorder recorder;
}


Recorder::~Recorder()
{
}


void Recorder::start()
{
	const int sampleRate = 16000; // Sphinx requires 16kHz sample rate
	recorder.start(sampleRate);
}


void Recorder::stop()
{
	recorder.stop();
}


const sf::SoundBuffer& Recorder::getBuffer()
{
	return recorder.getBuffer();
}


void Recorder::playBuffer(int bufferLengthMs)
{
	sf::Sound sound(getBuffer());
	sound.play();
	Sleep(bufferLengthMs);
}