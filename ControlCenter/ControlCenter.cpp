// ControlCenter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Recorder.h"
#include "Recognizer.h"


void captureAudioToFile(std::string outFilename)
{
	const int captureTestLengthMs = 3000;
	// Prepare objects
	Recorder recorder;

	// Record some data
	recorder.start();
	std::cout << "STARTED RECORDING\n";
	Sleep(captureTestLengthMs);
	std::cout << "END RECORDING RECORDING\n";
	recorder.stop();

	// Play it
	recorder.debugInfo();
	recorder.playBuffer(captureTestLengthMs);


	recorder.getBuffer().saveToFile(outFilename);
}


void recognizeAndPrintFromFile(std::string outFilename)
{
	Recognizer recognizer;
	recognizer.recognize(outFilename);
	recognizer.cleanup();
}


int main(int argc, char *argv[])
{
	captureAudioToFile("out.raw");
	recognizeAndPrintFromFile("out.raw");

	std::cin.get();
	return 0;
}