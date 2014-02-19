#pragma once

#include <pocketsphinx.h>
#include <string>

class Recognizer
{
private:
	cmd_ln_t *config;
	ps_decoder_t *ps;
	
public:
	Recognizer();
	~Recognizer();


	std::string recognize(std::string inputFilename);
	void cleanup();
};

