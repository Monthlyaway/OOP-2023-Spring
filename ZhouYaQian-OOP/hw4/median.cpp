#include <vector>
#include <algorithm>
#include "debug.h"

using namespace std;


double median(vector<double> vec)
{
	// vec is a copy
	int size = vec.size();
	sort(vec.begin(), vec.end());

	if (size % 2 == 0)
		return (vec[size / 2 - 1] + vec[size / 2]) / 2;
	else
		return vec[(size - 1) / 2];
}
double average(const vector<double>& vec)
{
	vector<double>::const_iterator iter = vec.begin();
	vector<double>::const_iterator end = vec.end();
	double total = 0;
	for (; iter != end; iter++)
		total += *iter;
	return total / vec.size();
}