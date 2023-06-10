#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include <iostream>
#include <string>

using namespace std;

class Calculator {
public:
	Calculator() : _result(0.0f), _equation(" ") {}
	void add(double num);
	void subtract(double num);
	void multiply(double num);
	void divide(double num);
	void clear();
	void printWithStars() const;
	double getResult() const;
private:
	double _result;
	string _equation;
};

#endif
