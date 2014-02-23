#pragma once

class std::string;

class CommandHandler
{
public:
	CommandHandler()
	{
		
	}

	virtual ~CommandHandler()
	{
	}


	virtual void handle(std::string sentence)
	{

	}
};

