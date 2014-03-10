#include "stdafx.h"
#include "SpeechSynthesizer.h"
#include <sapi.h>

//const LPCWSTR speed = L"<rate speed='-3'>";

SpeechSynthesizer::SpeechSynthesizer()
{
}

SpeechSynthesizer::~SpeechSynthesizer()
{
}

void SpeechSynthesizer::say(std::string sentence)
{
	ISpVoice * pVoice = NULL;
	HRESULT hr = NULL;
	//std::wstring toSay = speed+std::wstring(sentence.begin(), sentence.end());

	std::wstring say = std::wstring(L"<rate speed='-3'>")+std::wstring(sentence.begin(), sentence.end());
    hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);

	if(SUCCEEDED(hr))
    {
		pVoice->Speak(say.c_str(), 0, NULL);
		pVoice->Release();
		pVoice = NULL;
	}
	::CoUninitialize();
}