#include "algorithm.h"
#include "Student_info.h"
#define DEBUG

using std::istream;
using std::vector;
using std::cin;
using MySpace::find;

istream & read_hw(istream & in, vector<double> & hw)
{
	if(in){
		hw.clear();
		double x;//a variable into which to read
		while(in >> x){
			hw.push_back(x);
		}
		if (!in.eof())
			in.clear();
	}
	return in;
}
istream & read(istream & is, Student_info &s)
{
	is >> s.name >>s.midterm >>s.final;
	read_hw(is, s.homework);
	DEBUG_OUTPUT("reading " << s.name << "'s data");
	return is;
}
bool compare(const Student_info &x, const Student_info &y)
{
	return x.name < y.name;
}

bool did_all_hw(const Student_info & s)
{
	//检测homework所有的值中是否包含0
	return((MySpace::find(s.homework.begin(), s.homework.end(), 0))
		== s.homework.end());
}
