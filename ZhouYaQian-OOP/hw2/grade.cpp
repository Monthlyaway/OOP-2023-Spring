#include <vector>
#include <stdexcept>
#include "grade.h"
#include "median.h"

using namespace std;

double grade(double midterm, double final, const vector<double>& hw)
{
	double med = median(hw);
	double aver = average(hw);
	return 0.2 * midterm + 0.4 * final + 
		0.4 * (0.6 * aver + 0.4 * med);
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s)  // return whether this student failed
{
	return grade(s) < 60;
}
