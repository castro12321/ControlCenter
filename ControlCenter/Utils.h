#pragma once

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems, int limit = INT_MAX)
{
	std::stringstream ss(s);
	std::string item;
	
	int i = 0;
	while (std::getline(ss, item, delim))
	{
		elems.push_back(item);
		if (i++ >= limit)
			break;
	}
	return elems;
}


std::vector<std::string> split(const std::string& s, char delim, int limit = INT_MAX)
{
	std::vector<std::string> elems;
	return split(s, delim, elems, limit);
}