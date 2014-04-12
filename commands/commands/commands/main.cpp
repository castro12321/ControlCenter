#include "Commands.h"
#include <sstream>

void main(int argc, char * argv[])
{
	Commands command;
	std::stringstream ss;
	std::string sentence;

	if (argc > 1)
	{
		ss << argv[1];
		ss >> sentence;
		command.recognizeCommand(sentence);
	}
}