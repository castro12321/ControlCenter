#pragma once

#include <string>

class SpeechSynthesizer
{
public:
	SpeechSynthesizer();
	~SpeechSynthesizer();
	
	void say(std::string sentence);
};