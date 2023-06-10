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
		<< "�ܳ�: " << perimeter()
		<< "\t���: " << area() << "\n" << endl;
	return os;
}
