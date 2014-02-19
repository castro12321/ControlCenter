#pragma once

#include <SFML\Audio.hpp>

class Recorder
{
private:
	sf::SoundBufferRecorder recorder;

public:
	Recorder();
	~Recorder();

	void start(); // Start the capture
	void stop();  // Stop  the capture
	const sf::SoundBuffer& getBuffer();

	void playBuffer(int bufferLengthMs); // For testing purpose
};