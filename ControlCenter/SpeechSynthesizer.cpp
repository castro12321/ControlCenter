#include "stdafx.h"
#include "SpeechSynthesizer.h"
#include <sapi.h>

SpeechSynthesizer::SpeechSynthesizer()
{
}

SpeechSynthesizer::~SpeechSynthesizer()
{
}

void SpeechSynthesizer::say(std::string sentence)
{
	ISpVoice* pVoice = NULL;
	if (FAILED(::CoInitialize(NULL)))
		std::cout << "Something went wrong in SpeechSynthesizer.cpp\n";
	std::wstring say = std::wstring(L"<rate speed='-3'>")+std::wstring(sentence.begin(), sentence.end());
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr))
	{
		pVoice->Speak(say.c_str(), 0, NULL);
		pVoice->Release();
		pVoice = NULL;
	}
	::CoUninitialize();
}