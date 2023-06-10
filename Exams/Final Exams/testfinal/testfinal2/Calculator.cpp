#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

void Calculator::add(double num)
{
	_equation = to_string(_result) + " + " + to_string(num) + " = " + to_string(_result + num);
	_result += num;
}
void Calculator::subtract(double num) {
	_equation = to_string(_result) + " - " + to_string(num) + " = " + to_string(_result + num);
	_result -= num;
}
void Calculator::multiply(double num) {

	_equation = to_string(_result) + " * " + to_string(num) + " = " + to_string(_result + num);
	_result *= num;
}
void Calculator::divide(double num) {
	if (!num)
		throw runtime_error("Error: Cannot divide by zero");
	_equation = to_string(_result) + " / " + to_string(num) + " = " + to_string(_result + num);
	_result /= num;
}
void Calculator::clear() {
	_equation.clear();
	_result = 0;
}
void Calculator::printWithStars() const {
	string line(_equation.size() + 4, '*');
	cout << line << endl;
	cout << "* " << _equation << " * " << endl;
	cout << line << endl;
}
double Calculator::getResult() const {
	return _result;
}
