#pragma once

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;
class Good {
public:
	Good(std::string name, int count = 0)
		: _name(name), _count(count) {
		if (_count < 0)
		{
			cout << "Error: " << _name << " count can not be negative, resetting it to 0" << endl;
			_count = 0;
		}
	}
	Good(const Good& rhs) : _name(rhs._name), _count(rhs._count) {}
	Good& operator=(const Good& rhs) {
		if (this != &rhs) {
			_name = rhs._name;
			_count = rhs._count;
		}
		return *this;
	}

	std::string name() const { return _name; }
	int count() const { return _count; }
private:
	std::string _name;
	int _count;
};

class Stock {
public:
	friend ostream& operator<<(ostream& os, const Stock& s)
	{
		os << "\n----------------------------------------------------" << endl;
		os << "Current Stock:" << endl;
		for (auto iter = s._record.begin(); iter != s._record.end(); iter++)
		{
			os << setw(10) << left << iter->first << iter->second << endl;
		}
		os << "----------------------------------------------------" << endl;
		return os;
	}
	void purchase(const Good& good) {
		_record[good.name()] += good.count();
	}
	void sell(const Good& g)
	{
		if (_record.find(g.name()) == _record.end())
		{
			throw invalid_argument("Error: cannot sell nonexistent good");
		}
		else if (_record[g.name()] < g.count())
		{
			throw domain_error("Error: Insufficient inventory of " + g.name());
		}
		else
		{
			_record[g.name()] -= g.count();
			cout << "Sold " << g.count() << " " << g.name() << "(s)" << endl;
			if (_record[g.name()] == 0)
				throw domain_error("Warning: Inventory of " + g.name() + " is 0");
			else
				cout << "Remain " << _record[g.name()] << " " << g.name() << " in stock" << endl;
		}

	}
	void print(void) {
		for (auto iter = _record.begin(); iter != _record.end(); iter++)
		{
			cout << setw(10) << left << iter->first;
			cout << iter->second << endl;
		}
	}
private:
	std::map<std::string, double> _record;
};
