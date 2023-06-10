#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
* use split to store the strings in a vector
* if string is present: increase value by 1
* if string is not present: create a new key-value pair
*/

std::vector<string> split(const std::string& s)
{
	string delimiter = " ";
	string::size_type start = 0, end = s.find_first_of(delimiter);
	vector<string>tokens;
	string stp;

	while (end != string::npos)
	{
		tokens.push_back(s.substr(start, end - start));
		start = s.find_first_not_of(delimiter, end);
		end = s.find_first_of(delimiter, start);  // if is not found, return npos, ends the loop
	}  // which leaves the last word not pushed into tokens

	if (start != string::npos)
		tokens.push_back(s.substr(start));
	// If len is not passed as a parameter, then returned sub-string is [pos, size()).

	return tokens;
}

int main(void) 
{ 
	string stp;
	vector<string> tokens, svec;
	map<string, int> smap;

	while (getline(cin, stp)) {
		tokens = split(stp);
		//svec.insert(svec.end(), tokens.begin(), tokens.end());
		copy(tokens.begin(), tokens.end(), back_inserter(svec));
	}

	for (auto u : svec) {
		if (smap.count(u))  // already present
			smap[u]++;
		else
			smap[u] = 1;
	}

	for (auto u : smap) {
		cout << u.first << "\t\t" << u.second << endl;
	}
    
	return 0; 
}
