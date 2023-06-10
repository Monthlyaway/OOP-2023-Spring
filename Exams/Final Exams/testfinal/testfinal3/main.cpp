#include<iostream>
#include "Point.h"
#include "Line.h"
using namespace std;


int main() {
	Point p1(1, 1);
	Point p2(3, 4);
	Point p3 = p1 + p2;

	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;

	Line line(p1, p2);
	Line line2(line);

	cout << "Line length: " << line.length() << endl;
	cout << "Line2 length: " << line2.length() << endl;

	cout << line << "\n" << line2 << endl;

	Point p4(p2 + "(9.5,9.6)");
	cout << p4 << endl;

	return 0;
}
