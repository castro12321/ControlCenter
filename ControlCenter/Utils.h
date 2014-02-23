#pragma once

#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string>& split(const string &s, char delim, vector<string> &elems, int limit = INT_MAX)
{
	stringstream ss(s);
	string item;
	
	int i = 0;
	while (std::getline(ss, item, delim))
	{
		elems.push_back(item);
		if (i++ >= limit)
			break;
	}
	return elems;
}


vector<string> split(const string& s, char delim, int limit = INT_MAX)
{
	vector<string> elems;
	return split(s, delim, elems, limit);
}