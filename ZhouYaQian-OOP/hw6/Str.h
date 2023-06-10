#ifndef _STRING_H
#define _STRING_H

#include <algorithm>
#include <iostream>
#include "Vec.h"

using namespace std;

class Str : public Vec<char> {
public:
	Str() : Vec() {}
	Str(size_t n, char c) : Vec<char>(n, c) {}
	friend istream& operator>>(istream& is, Str& str);
	Str operator+(const char* rhs) const;
	friend Str operator+(const char* lhs, const Str& rhs);
	friend ostream& operator<<(ostream& os, const Str& str);
};
#endif
