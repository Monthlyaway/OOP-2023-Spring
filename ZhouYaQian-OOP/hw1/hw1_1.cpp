#include <iostream>
#include <fstream>
#include <iomanip>  // for setprecision()
#include <ios>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() 
{ 
	ifstream infile("hw1_1_input.txt");
	if (!infile)
	{
		cerr << "Oops: can not open file \"hw1_1_input.txt\", exit." << endl;
		return -1;
	}

	cout << "Please enter your name:" << endl;
	string name;
	infile >> name;
	cout << "Hello, " << name << "!" << endl;

	cout << "Please enter you midterm and final exam grades:" << endl;
	vector<double> data;
	double grade;
	infile >> grade; data.push_back(grade);
	infile >> grade; data.push_back(grade);

	cout << "Enter all your homework grades, followed by end-of-file: " << endl;
	while (infile >> grade)
		data.push_back(grade);

	sort(data.begin() + 2, data.end());
	double mid;
	int size = data.size();
	if (size % 2)  // odd number
		mid = data[(1 + size) / 2];
	else
		mid = (data[size / 2] + data[size / 2 + 1]) / 2;

	double result = 0.2 * data[0] + 0.4 * data[1] + 0.4 * mid;
	cout << fixed << setprecision(1);
	cout << "Your final grade is "
		<< result << endl;

	/* TIPS
	* std::fixed
	* It write floating-point values in fixed-point notation. 
	* The value is represented with exactly as many digits 
	* in the decimal part as specified by the precision field 
	* (precision) and with no exponent part.
	*/

	return 0; 
} 
