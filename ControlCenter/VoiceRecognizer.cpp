#include "stdafx.h"
#include "VoiceRecognizer.h"

#include "Config.h"

#define _CRT_SECURE_NO_WARNINGS

VoiceRecognizer::VoiceRecognizer()
{
	config = cmd_ln_init(NULL, ps_args(), TRUE,
		"-hmm",  "modeldir/acoustic",
		"-lm",   "modeldir/language/turtle.dmp",
		"-dict", "modeldir/dictionary/dic.dic",
		NULL);
	
	if (config == NULL)
		std::cerr << "Cannot initialize config";
	ps = ps_init(config);
	
	if (ps == NULL)
		std::cerr << "Cannot initialize ps";
}


VoiceRecognizer::~VoiceRecognizer()
{
}


std::string VoiceRecognizer::recognize(std::string inputFilename) // <---------- return command
{
	int32 score;
	const char *uttid;

	FILE* fh = fopen(inputFilename.c_str(), "rb");
	if (fh == NULL)
		std::cerr << "Failed to open " + inputFilename;

	int rv = ps_decode_raw(ps, fh, NULL, -1);
	if (rv < 0)
		std::cerr << "Number of frames of data searched < 0";
	
	const char* hyp = ps_get_hyp(ps, &score, &uttid);
	if (hyp == NULL)
		std::cerr << "hyp == NYLL";

	std::cout << "Recognition info: score=" << score << " uttid=" << *uttid << "\n";
	printf("Recognized: %s\n", hyp);
	return std::string(hyp);
}


void VoiceRecognizer::cleanup()
{
	ps_free(ps);
}