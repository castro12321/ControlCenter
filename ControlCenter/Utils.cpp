#include "stdafx.h"
#include "Utils.h"
#include <dirent.h>

std::vector<std::string>& Utils::split(const std::string &s, char delim, std::vector<std::string> &elems, int limit)
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


std::vector<std::string> Utils::split(const std::string& s, char delim, int limit)
{
	std::vector<std::string> elems;
	return split(s, delim, elems, limit);
}


std::string Utils::extractStringBetween(std::string& source, std::string& before, std::string& after)
{
	size_t first = source.find(before);
	size_t last  = source.find(after);
	if (first == std::string::npos || last == std::string::npos)
		return "";
	return source.substr(first+before.length(), last-(first+before.length()));
}


std::string Utils::trim(std::string sentence)
{
	std::stringstream trimmer;
	trimmer << sentence;
	sentence.clear();
	trimmer >> sentence;
	return sentence;
}


std::vector<std::string> Utils::getDeclaredApplications()
{
	std::vector<std::string> applications;

	DIR* dir = opendir("programs/");
	dirent* ent;
	if (dir != NULL)
		while ((ent = readdir(dir)) != NULL)
			applications.push_back(ent->d_name);
	else
		std::cout << "could not open directory" << std::endl;
	closedir(dir);

	return applications;
}