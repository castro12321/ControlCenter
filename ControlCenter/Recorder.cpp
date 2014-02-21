#include "stdafx.h"
#include "Recorder.h"

Recorder::Recorder()
{
	// first check if an input audio device is available on the system
	if (!sf::SoundBufferRecorder::isAvailable())
		throw "audio capture is not available on this system";

	// create the recorder
	sf::SoundBufferRecorder recorder;
}


Recorder::~Recorder()
{
}


void Recorder::start()
{
	const unsigned int sampleRate = 16000; // Sphinx requires 16kHz sample rate
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


void Recorder::debugInfo()
{
	sf::SoundBuffer buffer = getBuffer();

	float        duration     = buffer.getDuration().asSeconds();
	unsigned int sampleRage   = buffer.getSampleRate();
	unsigned int channelCount = buffer.getChannelCount();
	std::size_t  sampleCount  = buffer.getSampleCount();

	std::cout << "Sound information: " << std::endl;
	std::cout << duration     << " seconds" << std::endl;
	std::cout << sampleRage   << " samples / seconds" << std::endl;
	std::cout << channelCount << " channels" << std::endl;
	std::cout << sampleCount  << " samples" << std::endl;
}