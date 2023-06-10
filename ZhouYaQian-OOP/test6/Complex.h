#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>
#include <algorithm>
#include <string>

class Complex
{
public:
    Complex(double r = 0, double i = 0);
    Complex(double r);

    Complex& operator+=(const Complex& rhs);
    Complex operator+(const Complex& rhs);

    friend std::istream& operator>>(std::istream& is, Complex& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Complex& rhs);
    friend Complex operator+(int lhs, const Complex& rhs);

private:
    double _real;
    double _image;
};

#endif
