#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include "debug.h"
#include "grade.h"
#include "Student_info.h"
using namespace std;


int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	/*string infilename{"hw4_input.txt"};
	ifstream infile(infilename);
	if (!infile.is_open())
	{
		cerr << "Error: can not open " << infilename << endl;
		exit(3);
	}*/

	while (record.read(cin)) {
		if (record.name().size() > maxlen)
			maxlen = record.name().size();
		students.push_back(record);
	}
	students.push_back(record);

	sort(students.begin(), students.end(), compare);
	for (std::vector<Student_info>::iterator iter = students.begin(); iter != students.end(); iter++) {
		cout << iter->name()
			<< string(maxlen + 1 - iter->name().size(), ' ');
		try {
			double final_grade = iter->grade();
			streamsize prec = cout.precision();
			cout << "Your final grade is " << setprecision(3)
				<< final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	//infile.close();
	return 0;
}
