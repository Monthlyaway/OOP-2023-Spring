#ifndef GUARD_CORE
#define GUARD_CORE

#include <string>
#include <istream>
#include <iostream>
#include "Vec.h"


class Core{
    //TODO

};

bool compare(const Core &x, const Core &y);
bool compare_grade(const Core &x, const Core &y);
bool compare_grade_ptr(const Core *x, const Core *y);
std::istream & read_hw(std::istream & in, Vec<double> & hw);

#endif
