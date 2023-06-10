#include "Str.h"
istream& operator>>(istream& is, Str& str)
{
	char ctp;
	while (is.get(ctp) && !isspace(ctp)) {
		str.push_back(ctp);
	}
	return is;
}
Str Str::operator+(const char* rhs) const
{
	Str temp;
	for (size_t i = 0; i < size(); i++) {
		temp.push_back((*this)[i]);
	}
	for (size_t i = 0; i < strlen(rhs); i++) {
		temp.push_back(rhs[i]);
	}
	return temp;
}
Str operator+(const char* lhs, const Str& rhs)
{
	Str temp;
	for (size_t i = 0; i < strlen(lhs); i++) {
		temp.push_back(lhs[i]);
	}
	for (size_t i = 0; i < rhs.size(); i++) {
		temp.push_back(rhs[i]);
	}
	return temp;
}
ostream& operator<<(ostream& os, const Str& str)
{
	for (size_t i = 0; i < str.size(); i++) {
		os << str[i];
	}
	return os;
}