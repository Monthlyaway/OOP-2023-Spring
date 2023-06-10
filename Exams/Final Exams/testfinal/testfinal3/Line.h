#ifndef _Line_H
#define _Line_H
#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std; 

class Line {
	friend ostream& operator<<(ostream& os, const Line& rhs) {
		os << "Line: " << rhs._p1 << " to " << rhs._p2;
		return os;
	}
public:
	Line(double x1, double y1, double x2, double y2)
		: _p1(x1, y1), _p2(x2, y2) {}
	Line(const Point& p1, const Point& p2)
		: _p1(p1), _p2(p2) {}
	Line(const Line& rhs) {
		_p1 = rhs._p1;
		_p2 = rhs._p2;
	}
	Line& operator=(const Line& rhs) {
		if (this != &rhs) {
			_p1 = rhs._p1;
			_p2 = rhs._p2;
		}
		return *this;
	}
	double length() const {
		return std::sqrt((_p1.x() - _p2.x()) * (_p1.x() - _p2.x()) +
			(_p1.y() - _p2.y()) * (_p1.y() - _p2.y()));
	}

private:
	Point _p1;
	Point _p2;
};


#endif
