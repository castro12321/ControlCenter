// ControlCenter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

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


/*
const sf::Int16* samples = buffer.getSamples();
int sampleRate  = buffer.getSampleRate();
int sampleCount = buffer.getSampleCount();
std::cout << sampleRate << " " << sampleCount << "\n";
*/





/* Working example of Sphinx
int main(int argc, char *argv[])
{

fh = fopen("goforward.raw", "rb");
if (fh == NULL) {
perror("Failed to open goforward.raw");
return 1;
}

// Decode example #1
rv = ps_decode_raw(ps, fh, "goforward", -1);
if (rv < 0)
return 1;
hyp = ps_get_hyp(ps, &score, &uttid);
if (hyp == NULL)
return 1;
printf("Recognized: %s\n", hyp);

// Decode example #2
fseek(fh, 0, SEEK_SET);
rv = ps_start_utt(ps, "goforward");
if (rv < 0)
return 1;
while (!feof(fh)) {
size_t nsamp;
nsamp = fread(buf, 2, 512, fh);
rv = ps_process_raw(ps, buf, nsamp, FALSE, FALSE);
}

rv = ps_end_utt(ps);
if (rv < 0)
return 1;
hyp = ps_get_hyp(ps, &score, &uttid);
if (hyp == NULL)
return 1;
printf("Recognized: %s\n", hyp);

// Cleanup
fclose(fh);
}
*/











/* Working example of Sphinx
int main(int argc, char *argv[])
{
	ps_decoder_t *ps;
	cmd_ln_t *config;
	FILE *fh;
	char const *hyp, *uttid;
	int16 buf[512];
	int rv;
	int32 score;
	
	// init
	config = cmd_ln_init(NULL, ps_args(), TRUE,
		"-hmm",  MODELDIR "/hmm/en_US/hub4wsj_sc_8k",
		"-lm",   MODELDIR "/lm/en/turtle.DMP",
		"-dict", MODELDIR "/lm/en/turtle.dic",
		NULL);
	if (config == NULL)
		return 1;
	ps = ps_init(config);
	if (ps == NULL)
		return 1;
	
	fh = fopen("goforward.raw", "rb");
	if (fh == NULL) {
		perror("Failed to open goforward.raw");
		return 1;
	}
	
	// Decode example #1
	rv = ps_decode_raw(ps, fh, "goforward", -1);
	if (rv < 0)
		return 1;
	hyp = ps_get_hyp(ps, &score, &uttid);
	if (hyp == NULL)
		return 1;
	printf("Recognized: %s\n", hyp);
	
	// Decode example #2
	fseek(fh, 0, SEEK_SET);
	rv = ps_start_utt(ps, "goforward");
	if (rv < 0)
		return 1;
	while (!feof(fh)) {
		size_t nsamp;
		nsamp = fread(buf, 2, 512, fh);
		rv = ps_process_raw(ps, buf, nsamp, FALSE, FALSE);
	}
	
	rv = ps_end_utt(ps);
	if (rv < 0)
		return 1;
	hyp = ps_get_hyp(ps, &score, &uttid);
	if (hyp == NULL)
		return 1;
	printf("Recognized: %s\n", hyp);
	
	// Cleanup
	fclose(fh);
	ps_free(ps);

	std::cin.get();

	return 0;
}
*/