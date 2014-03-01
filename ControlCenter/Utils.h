#pragma once

#include <vector>
#include <string>
#include <sstream>

namespace Utils
{
	std::vector<std::string> split(const std::string& s, char delim, int limit = INT_MAX); // Splits the string into a substrings into the vector.
	std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems, int limit = INT_MAX);

	// Returns all application names declared in ./programs dir.
	std::vector<std::string> getDeclaredApplications();
};


