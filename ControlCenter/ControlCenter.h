#pragma once

#include "VoiceRecognizer.h"
#include "VoiceRecorder.h"
#include "CommandRecognizer.h"

class ControlCenter
{
public:
	CommandRecognizer cmmndRecognizer;
	VoiceRecognizer   voiceRecognizer;
	VoiceRecorder     voiceRecorder;

	ControlCenter();
	~ControlCenter();

	void run();
	void record();
};

