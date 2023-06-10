#include "Student_info.h"
#include "debug.h"
#include "grade.h"

using namespace std;

double Student_info::grade() const { return ::grade(midterm, final, homework); }

std::istream& Student_info::read(std::istream& is)
{
    is >> n >> midterm >> final;
    if (is) {
        homework.clear();
        double x;
        while (is >> x)
            homework.push_back(x);
        if (!is.eof())
            is.clear();
    }
    return is;
}
bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}
