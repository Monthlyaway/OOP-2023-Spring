#include "Core.h"
#include "grade.h"

using namespace std;
std::string Core::name() const 
{ 
	return n;
}

double Core::grade() const
{
	return ::grade(midterm, final, homework);
}
istream& Core::read_common(std::istream& in)
{
	in >> n >> midterm >> final;
	return in;
}
istream& Core::read(std::istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}
bool compare_grades(const Core& x, const Core& y) {
	return x.grade() < y.grade();
}
bool compare(const Core& x, const Core& y) {
	return x.name() < y.name();
}
bool compare_grade(const Core &x, const Core &y)
{
return x.grade() < y.grade();
}

istream& read_hw(istream& in, Vec<double>& hw)
{
	if (in) {
		hw.clear();
		double x;//a variable into which to read
		while (cin >> x) {
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}