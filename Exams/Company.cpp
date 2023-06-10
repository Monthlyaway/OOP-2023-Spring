#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Employee {
	//friend class Company;
public:
	Employee(string name) : _name(name) {}
	virtual ~Employee() {};
	string name(void) const {
		return _name;
	}

	virtual double salary(void) const = 0;
private:
	string _name;
};

class Manager : public Employee {
public:
	Manager(string name, double hours = 0, double bonus = 0) : Employee(name), _hours(hours), _bonus(bonus) {}
	double salary(void) const {
		return 200 * _hours + _bonus;
	}
private:
	double _hours;
	double _bonus;
};

class Programmer : public Employee {
public:
	Programmer(string name, double hours = 0, double overtime = 0) : Employee(name), _hours(hours), _overtime(overtime) {}
	double salary(void) const {
		return 150 * _hours + 300 * _overtime;
	}
private:
	double _hours;
	double _overtime;
};

class Company {
public:
	void AddEmployee(Employee* newep) {
		_ep.push_back(newep);
	}
	void RemoveEmployee(string name) {
		for (auto iter = _ep.begin(); iter != _ep.end(); iter++) {
			if ((*iter)->name() == name) {
				_ep.erase(iter);
				return;
			}
		}
	}

	ostream& Print(ostream& os = cout) const {
		for (auto u : _ep) {
			os << u->name() << ": " << u->salary() << endl;
		}
		return os;
	}
private:
	vector<Employee*> _ep;
};


int main(void)
{
	Company cp;
	cp.AddEmployee(new Manager("Wang", 20, 500));
	cp.AddEmployee(new Programmer("Chen", 20, 10));
	cp.AddEmployee(new Programmer("Zhao", 30, 0));
	cp.RemoveEmployee("Chen");
	cp.AddEmployee(new Programmer("Lin", 15, 5));
	cp.Print();

	return 0;

}