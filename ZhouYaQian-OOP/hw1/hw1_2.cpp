#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // for find()
using namespace std;

int main() 
{ 
	//cout << "Input some strings, end with Ctrl^z" << endl;

	//// input strings to svec
	//string input;
	//vector<string> svec;
	//vector<int> strsize;
	//while (cin >> input)
	//{
	//	svec.push_back(input);
	//	strsize.push_back(input.size());
	//}

	//// display svec adn strsize
	//for (int i = 0; i < svec.size(); i++)
	//	cout << svec[i] << " " << strsize[i] << " ";
	//cout << endl;

	//// find the min and max number in strsize
	//int min = strsize[0], max = strsize[0];
	//for (int i = 1; i < strsize.size(); i++)
	//{
	//	if (strsize[i] < min)
	//		min = strsize[i];
	//	if (strsize[i] > max)
	//		max = strsize[i];
	//}
	//cout << "min = " << min << " , max = " << max << endl;

	//// output the corresponding word
	//vector<int>::const_iterator iter = strsize.begin();
	//vector<int>::const_iterator end = strsize.end();

	//cout << "longest: ";
	//while ((iter = find(iter, end, max)) != end)
	//{
	//	cout << svec[iter - strsize.begin()] << " ";
	//	iter++;
	//}
	//cout << endl;

	//iter = strsize.begin();
	//cout << "shortest: ";
	//while ((iter = find(iter, end, min)) != end)
	//{
	//	cout << svec[iter - strsize.begin()] << " ";
	//	iter++;
	//}

	cout << "Input some strings." << endl;
	string input;
	vector<string> svec;
	int min = 0;
	int max = 0;

	cin >> input;
	min = max = input.size();
	while (cin >> input) {
		svec.push_back(input);
		if (input.size() < min)
			min = input.size();
		else if (input.size() > max)
			max = input.size();
	}
	cout << "longest: " ;
	for (auto u : svec) {
		if (u.size() == max)
			cout << u << " ";
	}
	cout << endl;
	cout << "shortest: ";
	for (auto u : svec) {
		if (u.size() == min)
			cout << u << " ";
	}
	cout << endl;

	return 0; 
}
