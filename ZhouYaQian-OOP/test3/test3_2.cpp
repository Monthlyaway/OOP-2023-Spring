#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

std::vector<string> split(const std::string& s, char delimeter = ' ')
{
	vector<string> tokens;
	string  stp;
	int ix = 0;
	while (ix < s.size()) {
		if (s.at(ix) == delimeter) {
			if (!stp.empty())
				tokens.push_back(stp);
			stp.clear();
		}
		else
			stp.append(1, s.at(ix));
		ix++;
	}
	if (!stp.empty())
		tokens.push_back(stp);

	return tokens;
}

/*
* use a vector<int> to store line positions
*/
int main()
{
	string stp;
	map<string, vector<int> > smap;
	vector<string> svec;
	int line = 0;

	while (getline(cin, stp)) {
		line++;
		svec = split(stp);
		// sort, unique, erase
		sort(svec.begin(), svec.end());
		auto last = unique(svec.begin(), svec.end());
		svec.erase(last, svec.end());
		for (auto u : svec)
			smap[u].push_back(line);
		svec.clear();
	}

	for (auto u : smap) {
		cout << u.first << "  ";
		for (auto item : u.second)
			cout << item << " ";
		cout << endl;
	}
	return 0;
}