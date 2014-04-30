#include "stdafx.h"
#include "WebRequestListener.h"
#include "Utils.h"


bool wait(sf::TcpSocket& socket, sf::Time timeout)
{
	sf::SocketSelector selector;
	selector.add(socket);
	return selector.wait(timeout);
}


bool replace(std::string& str, const std::string& from, const std::string& to)
{
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}


void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
	while (replace(str, from, to))
		;
}


std::string extractSentenceFromRequest(std::string& request)
{
	std::string requestDelimiterBefore = "/speech/";
	std::string requestDelimiterAfter  = "?callback=jQuery";
	request = Utils::extractStringBetween(request, requestDelimiterBefore, requestDelimiterAfter);
	
	replaceAll(request, "%20"   , " ");

	// UTF-8 Unicode standard
	// Uppercase
	replaceAll(request, "%C4%84", "A");
	replaceAll(request, "%C4%86", "C");
	replaceAll(request, "%C4%98", "E");
	replaceAll(request, "%C5%81", "L");
	replaceAll(request, "%C5%83", "N");
	replaceAll(request, "%C3%93", "O");
	replaceAll(request, "%C5%9A", "S");
	replaceAll(request, "%C5%B9", "Z");
	replaceAll(request, "%C5%BB", "Z");

	// Lowercase
	replaceAll(request, "%C4%85", "a");
	replaceAll(request, "%C4%87", "c");
	replaceAll(request, "%C4%99", "e");
	replaceAll(request, "%C5%82", "l");
	replaceAll(request, "%C5%84", "n");
	replaceAll(request, "%C3%B3", "o");
	replaceAll(request, "%C5%9B", "s");
	replaceAll(request, "%C5%BA", "z");
	replaceAll(request, "%C5%BC", "z");

	return request;
}


WebRequestListener::WebRequestListener()
{
	// bind the listener to a port
	const unsigned port = 820;
	std::cout << "Launching listener on port " << port << std::endl;
	if (listener.listen(port) != sf::Socket::Done)
		std::cout << "Cannot listen on port 820\n";
}

/*
 * Returns the string that contains request or null if no request is available at the moment
 */
std::string WebRequestListener::nextSentence()
{
	// accept a new connection
	sf::TcpSocket client;
	client.setBlocking(false);
	std::cout << "Waiting for next client\n";
	if (listener.accept(client) != sf::Socket::Done)
	{
		std::cout << "Cannot accept client\n";
		return "";
	}

	std::cout << "Waiting for some data to receive\n";
	if (wait(client, sf::milliseconds(500)))
	{
		const int MAX_DATA_SIZE_BYTES = 1024;
		char data[MAX_DATA_SIZE_BYTES];
		std::size_t received;
		if (client.receive(data, MAX_DATA_SIZE_BYTES, received) != sf::Socket::Done)
			std::cout << "Error trying to receive data from client\n";
		std::cout << "Received " << received << " bytes" << std::endl;
		return extractSentenceFromRequest(std::string(data, received));
	}
	return "";
}


/* Just some examples of GET requests

GET /speech/%20teraz%20lepiej?callback=jQuery1110009784570219926536_139888416534
3&_=1398884165344 HTTP/1.1
Host: localhost:820
Connection: keep-alive
Accept: * / *
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/34.0.1847.131 Safari/537.36
Referer: http://kawinski.net/speech/
Accept-Encoding: gzip,deflate,sdch
Accept-Language: pl-PL,pl;q=0.8,en-US;q=0.6,en;q=0.4


GET /speech/%20nagrywaj?callback=jQuery1110009784570219926536_1398884165345&_=13
98884165346 HTTP/1.1
Host: localhost:820
Connection: keep-alive
Accept: * / *
User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/34.0.1847.131 Safari/537.36
Referer: http://kawinski.net/speech/
Accept-Encoding: gzip,deflate,sdch
Accept-Language: pl-PL,pl;q=0.8,en-US;q=0.6,en;q=0.4

*/