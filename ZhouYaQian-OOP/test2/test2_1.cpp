#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<string> split(const std::string& s)
{
	//string delimiter = " ";
	//string::size_type start = 0, end = s.find_first_of(delimiter);
	//vector<string>tokens;
	//string stp;

	//while (end != string::npos)
	//{
	//	tokens.push_back(s.substr(start, end - start));
	//	start = s.find_first_not_of(delimiter, end);
	//	end = s.find_first_of(delimiter, start);  // if is not found, return npos, ends the loop
	//}  // which leaves the last word not pushed into tokens

	//if (start != string::npos)
	//	tokens.push_back(s.substr(start));
	//// If len is not passed as a parameter, then returned sub-string is [pos, size()).

	vector<string> tokens;
	char delimeter = ' ';
	string  stp;
	int ix = 0;
	while (ix < s.size()) {
		if (s.at(ix) == delimeter) {
			if (!stp.empty())
				tokens.push_back(stp);
			stp.clear();
		}
		else {
			stp.append(1, s.at(ix));
		}
		ix++;
	}
	tokens.push_back(stp);

	return tokens;
}

int main() 
{
	string str = "I          am   from         Shanghai.";
	vector<string>tokens = split(str);
	for (auto u : tokens)
		cout << "\"" << u << "\" ";
	cout << endl;
	return 0;
}