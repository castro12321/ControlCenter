#include "stdafx.h"
#include "Recognizer.h"

#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
#define MODELDIR "D:\\gdrive\\Google Drive\\code\\c++\\api\\pocketsphinx\\model"

Recognizer::Recognizer()
{
	config = cmd_ln_init(NULL, ps_args(), TRUE,
		"-hmm", MODELDIR "/hmm/en_US/hub4wsj_sc_8k",
		"-lm", MODELDIR "/lm/en/turtle.DMP",
		"-dict", MODELDIR "/lm/en/turtle.dic",
		NULL);
	if (config == NULL)
		throw "Cannot initialize config";
	ps = ps_init(config);
	if (ps == NULL)
		throw "Cannot initialize ps";
}


Recognizer::~Recognizer()
{
}


std::string Recognizer::recognize(std::string inputFilename)
{
	int32 score;
	char const *uttid;

	FILE* fh = fopen(inputFilename.c_str(), "rb");
	if (fh == NULL)
		throw "Failed to open out.raw";

	int rv = ps_decode_raw(ps, fh, "goforward", -1);
	if (rv < 0)
		throw "Number of frames of data searched < 0";
	const char* hyp = ps_get_hyp(ps, &score, &uttid);
	if (hyp == NULL)
		throw "hyp == NYLL";

	std::cout << "Recognition info: score=" << score << " uttid=" << *uttid << "\n";
	printf("Recognized: %s\n", hyp);
	return std::string(hyp);
}


void Recognizer::cleanup()
{
	ps_free(ps);
}