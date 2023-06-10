#pragma once

#include <vector>
#include "Student_info.h"
using namespace std;

double grade(double midterm, double final, 
	const vector<double> & hw);
double grade(const Student_info &s);
bool fgrade(const Student_info &s);

