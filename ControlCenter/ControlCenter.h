#pragma once

#include "Recognizer.h"
#include "Recorder.h"
#include "CommandRecognizer.h"

class ControlCenter
{
public:
	CommandRecognizer command;
	Recognizer recognizer;
	Recorder   recorder;

	ControlCenter();
	~ControlCenter();

	void run();
	void record();
};

