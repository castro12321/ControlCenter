#pragma once

#include <SFML\Audio.hpp>

class VoiceRecorder
{
private:
	sf::SoundBufferRecorder recorder;

public:
	VoiceRecorder();
	~VoiceRecorder();

	void start(); // Start the capture
	void stop();  // Stop  the capture
	const sf::SoundBuffer& getBuffer();

	void playBuffer(); // For testing purpose
	void debugInfo();
};