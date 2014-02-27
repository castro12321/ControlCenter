#pragma once

#include <pocketsphinx.h>
#include <string>

class VoiceRecognizer
{
private:
	cmd_ln_t *config;
	ps_decoder_t *ps;
	
public:
	static std::string command;
	VoiceRecognizer();
	~VoiceRecognizer();

	std::string recognize(std::string inputFilename);
	void cleanup();
};

