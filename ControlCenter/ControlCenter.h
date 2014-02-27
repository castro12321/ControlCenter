#pragma once

#include "VoiceRecognizer.h"
#include "Recorder.h"
#include "CommandRecognizer.h"

class ControlCenter
{
public:
	CommandRecognizer command;
	VoiceRecognizer recognizer;
	Recorder   recorder;

	ControlCenter();
	~ControlCenter();

	void run();
	void record();
};

