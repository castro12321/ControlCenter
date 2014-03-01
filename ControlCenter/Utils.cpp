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