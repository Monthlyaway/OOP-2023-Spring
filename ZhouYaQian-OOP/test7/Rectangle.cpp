#include <iostream>
#include "Rectangle.h"

double myRectangle::perimeter(void) const {
	return 2 * (_width + _height);
}

double myRectangle::area(void) const {
	return _width * _height;
}

ostream& myRectangle::print(ostream& os) const {
	os << "\n--------------------------------\n"
		<< "           " << what_am_i() <<
		"\n--------------------------------\n"
		<< "周长: " << perimeter()
		<< "\t面积: " << area() << "\n" << endl;
	return os;
}
