#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class Vehicle {
public:
	typedef unsigned int ID;
	Vehicle(const string& model, const ID id, double rental_per_day) :
		_model(model), _id(id), _rental_per_day(rental_per_day), _days(0) {}
	virtual ~Vehicle() {}
	double cost(void) const {
		return _days * _rental_per_day;
	}
	void incrementDay() {
		_days++;
	}
	virtual ostream& print(ostream& os = cout) const {
		os << "Model: " << _model << endl;
		os << "ID: " << _id << endl;
		os << "Rental per day: " << _rental_per_day << endl;
		os << "Days rented: " << _days << endl;
		return os;
	}
	friend ostream& operator<<(ostream& os, const Vehicle& rhs) {
		rhs.print();
		return os;
	}

private:
	unsigned int _days;
	double _rental_per_day;
	ID _id;
	string _model;
};

class Car : public Vehicle {
public:
	Car(const string& model, const ID id, double rental_per_day, int doors, const string& fuel) : Vehicle(model, id, rental_per_day), _doors(doors), _fuel(fuel) {}
	ostream& print(ostream& os = cout) const  override {
		Vehicle::print(os);
		os << "Number of doors: " << _doors << endl;
		os << "Fuel type: " << _fuel << endl;
		return os;
	}
private:
	int _doors;
	string _fuel;
};

int main(void)
{
	Car toyota("Toyota", 100026, 26, 4, "cc");
	cout << toyota;

	return 0;
}