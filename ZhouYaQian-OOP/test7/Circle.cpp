#include <iostream>
#include <algorithm>
#include "Circle.h"

#define PI 3.1415926

double myCircle::perimeter(void) const {
	return 2 * PI * _radius;
}

double myCircle::area(void)const {
	return PI * _radius * _radius;
}

ostream& myCircle::print(ostream& os) const {
	os << "\n--------------------------------\n"
		<< "           " << what_am_i() <<
		"\n--------------------------------\n"
		<< "周长: " << perimeter()
		<< "\t面积: " << area() << "\n" << endl;
	return os;
}