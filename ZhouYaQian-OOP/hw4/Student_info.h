#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <vector>
#include <iostream>
#include <fstream>

class Student_info{
public:
	double grade() const;
	std::istream& read(std::istream&);
	bool valid()const { return homework.empty(); }
	std::string name() const { return n; }
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y);

#endif
