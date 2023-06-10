#include "Grad.h"
#include "grade.h"
#include <algorithm>

using namespace std;
double Grad::grade() const
{
	return std::min(Core::grade(), thesis);
}
istream& Grad::read(std::istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in, Core::homework);// »ò£ºread_hw(in, Core::homework);
	return in;
}