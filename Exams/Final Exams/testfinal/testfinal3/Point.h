#ifndef _Point_H
#define _Point_H
#include <iostream>
#include <sstream>

using namespace std;
class Point {
public:
	Point(double x = 0.0, double y = 0.0) : _x(x), _y(y) {}
	Point(const Point& rhs) : _x(rhs._x), _y(rhs._y) {}
	Point(const std::string& str) {
		char ch1 = '(', ch2 = ',', ch3 = ')';
		std::istringstream iss(str);
		iss >> ch1 >> _x >> ch2 >> _y >> ch3;
	}

	Point& operator=(const Point& rhs) {
		if (this != &rhs) {
			_x = rhs._x;
			_y = rhs._y;
		}
		return *this;
	}

	Point operator+(const Point& rhs) const {
		return Point(_x + rhs._x, _y + rhs._y);
	}
	Point operator+(const string& str) const {
		Point rhs(str);
		return *this + rhs;
	}

	bool operator==(const Point& rhs) const {
		return (_x == rhs._x) && (_y == rhs._y);
	}

	ostream& print(ostream& os = cout) const {
		os << "(" << _x << ", " << _y << ")";
		return os;
	}

	double x() const { return _x; }
	double y() const { return _y; }

	double x(double newx) { _x = newx; return _x; }
	double y(double newy) { _y = newy; return _y; }

	friend ostream& operator<<(ostream& os, const Point& rhs) {
		return rhs.print(os);
	}

private:
	double _x;
	double _y;
};


#endif
