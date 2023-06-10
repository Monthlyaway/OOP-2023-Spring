#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"
using namespace std;
class myCircle : public myShape {
public:
	myCircle(double radius) : _radius(radius) {}
	double perimeter(void) const;
	double area(void) const;
	ostream& print(ostream& os = cout) const;
	string what_am_i(void) const {
		return "Circle";
	}

private:
	double _radius;
};

#endif
