#pragma once
#include "CommandHandler.h"
#include "SpeechSynthesizer.h"

class ShowTimeHandler : public CommandHandler
{
private:
	SpeechSynthesizer synthesizer;
public:
	enum SHOW {SHOW_TIME, SHOW_DATE};
	SHOW show;

	ShowTimeHandler(SHOW value);
	virtual ~ShowTimeHandler();

	void handle(std::string sentence, std::vector<std::string> words) override;
};