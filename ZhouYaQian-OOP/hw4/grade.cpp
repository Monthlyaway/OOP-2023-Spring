#include <vector>
#include <stdexcept>
#include "debug.h"
#include "grade.h"
#include "median.h"

double grade(double midterm, double final, const vector<double>& hw)
{
	double med = median(hw);
	double aver = average(hw);
	return 0.2 * midterm + 0.4 * final +
		0.4 * med;
}

