#pragma once
#include <SFML\Network.hpp>

class WebRequestListener
{
private:
	sf::TcpListener listener;

public:
	WebRequestListener();
	std::string nextSentence();
};