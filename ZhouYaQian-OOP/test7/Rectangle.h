#ifndef _Rectangle_H
#define _Rectangle_H
#include "Shape.h"
using namespace std;
class myRectangle : public myShape {
public:
	myRectangle(double width, double height) : _width(width), _height(height) {}
	double perimeter(void) const;
	double area(void) const;
	ostream& print(ostream& os = cout) const;
	string what_am_i(void) const {
		return "Rectangle";
	}

private:
	double _width;
	double _height;
};

#endif
