#ifndef _SHAPE_H
#define _SHAPE_H
#include <iostream>
#include <string>

using namespace std;
class myShape {
public:
	virtual ~myShape() {}
	virtual double perimeter(void) const = 0;
	virtual double area(void) const = 0;

	virtual ostream& print(ostream& os = cout) const = 0;
	virtual string what_am_i(void) const = 0;

	friend ostream& operator<<(ostream& os, const myShape& sh) {
		return sh.print(os);
	}
protected:
};

#endif
