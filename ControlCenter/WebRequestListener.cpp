#include "stdafx.h"
#include "WebRequestListener.h"


bool wait(sf::TcpSocket& socket, sf::Time timeout)
{
	sf::SocketSelector selector;
	selector.add(socket);
	return selector.wait(timeout);
}


WebRequestListener::WebRequestListener()
{
	// bind the listener to a port
	const unsigned port = 820;
	std::cout << "Launching listener on port " << port << std::endl;
	if (listener.listen(port) != sf::Socket::Done)
		std::cout << "Cannot listen on port 820\n";
}


std::string WebRequestListener::nextRequest()
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
		return std::string(data, received);
	}
	return "";
}