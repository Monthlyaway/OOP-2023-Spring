#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
using namespace std;

struct Student_info
{
	string name;
	double midterm;
	double final;
	vector<double> homework;
	bool operator<(const Student_info& n) const
	{
		return name < n.name;
	}
};

bool compare(const Student_info& x, const Student_info& y);
ifstream& read(ifstream& is, Student_info& student);
ifstream& read_hw(ifstream& is, vector<double>& hw);

