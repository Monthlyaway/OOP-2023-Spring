#ifndef GUARD_GRAD
#define GUARD_GRAD

#include <string>
#include <istream>
#include <iostream>
#include "Vec.h"
#include "Core.h"

class Grad : public Core {
public:
	Grad() : thesis(0) {}
	Grad(std::istream& is) { read(is); }

	double grade() const;
	std::istream& read(std::istream&);

	Grad* clone() const {
		return new Grad(*this);
	}
private:
	double thesis;

};
bool compare(const Core&, const Core&);
#endif
