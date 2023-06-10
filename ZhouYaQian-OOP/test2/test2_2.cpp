#include <iostream>
#include <string>
#include <vector>
using namespace std;

std::vector<string> frame(const std::vector<string>& svec)
{
	// find the max length
	int maxl = 0;
	for (auto u : svec)
		if (u.length() > maxl)
			maxl = u.length();
	//cout << "Max length = " << maxl << endl;

	vector<string> result;

	string first_and_last(maxl + 4, '*');
	result.push_back(first_and_last);

	string prefix = "* ";
	string sufix = " *";
	string element;
	for (int i = 0; i < svec.size(); i++)
	{
		string stp(maxl - svec.at(i).length(), ' ');
		element = prefix + svec.at(i) + stp + sufix;
		//cout << "element = " << element << endl;
		result.push_back(element);
	}
	result.push_back(first_and_last);  // the last line

	return result;
}

int main()
{
	vector<string> svec = { "This", "is", "an", "example", "to", "illustrate", "framing" };
	vector<string>framed_vec = frame(svec);
	for (auto u : framed_vec)
		cout << u << endl;

	return 0;
}

