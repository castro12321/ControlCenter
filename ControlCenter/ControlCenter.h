#pragma once

#include "Recognizer.h"
#include "Recorder.h"

class ControlCenter
{
public:
	Recognizer recognizer;
	Recorder   recorder;

	ControlCenter();
	~ControlCenter();

	void run();
	void record();
};

