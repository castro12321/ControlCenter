#pragma once
#include "CommandHandler.h"
#include "SpeechSynthesizer.h"

class SayTimeHandler : public CommandHandler
{
private:
	SpeechSynthesizer synthesizer;

public:
	enum COMMAND {SAY_TIME, SAY_DATE};
	COMMAND cammand;

	SayTimeHandler(COMMAND value);
	virtual ~SayTimeHandler();

	void handle(std::string sentence, std::vector<std::string> words) override;
};